#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <boost/noncopyable.hpp>
#include <boost/optional.hpp>
#include <boost/property_tree/ptree.hpp>
#include <sstream>
#include <string>

#include "valhalla/baldr/graphreader.h"
#include "valhalla/baldr/rapidjson_utils.h"
#include "valhalla/midgard/logging.h"
#include "valhalla/midgard/util.h"
#include "valhalla/mjolnir/util.h"
#include "valhalla/tyr/actor.h"

namespace vm = valhalla::mjolnir;
namespace vb = valhalla::baldr;
namespace py = pybind11;

namespace {

// statically set the config file and configure logging, throw if you never configured
// configuring multiple times is possible, e.g. to change service_limits
const boost::property_tree::ptree configure(const std::string& config_path,
                                             const std::string& tile_extract = "",
                                             py::dict config = {},
                                             bool verbose = true) {
  boost::property_tree::ptree pt;

  // only build config when called from binding's Configure!
  if (!config_path.empty()) {
    // create the config JSON on the filesystem via python and read it with rapidjson from file
    py::object create_config = py::module_::import("valhalla.config").attr("_create_config");
    create_config(config_path, tile_extract, config, verbose);
    try {
      // parse the config
      boost::property_tree::ptree temp_pt;
      rapidjson::read_json(config_path, temp_pt);
      pt = temp_pt;

      // configure logging
      boost::optional<boost::property_tree::ptree&> logging_subtree =
          pt.get_child_optional("loki.logging");
      if (logging_subtree) {
        auto logging_config = valhalla::midgard::ToMap<const boost::property_tree::ptree&,
                                                       std::unordered_map<std::string, std::string>>(
            logging_subtree.get());
        valhalla::midgard::logging::Configure(logging_config);
      }
    } catch (...) { throw std::runtime_error("Failed to load config from: " + config_path); }
  }

  return pt;
}
} // namespace

struct simplified_actor_t : public valhalla::tyr::actor_t {
  simplified_actor_t(const boost::property_tree::ptree& config)
      : valhalla::tyr::actor_t::actor_t(config, true) {
  }

  std::string route(const std::string& request_str) {
    return valhalla::tyr::actor_t::route(request_str, nullptr, nullptr);
  };
  std::string locate(const std::string& request_str) {
    return valhalla::tyr::actor_t::locate(request_str, nullptr, nullptr);
  };
  std::string optimized_route(const std::string& request_str) {
    return valhalla::tyr::actor_t::optimized_route(request_str, nullptr, nullptr);
  };
  std::string matrix(const std::string& request_str) {
    return valhalla::tyr::actor_t::matrix(request_str, nullptr, nullptr);
  };
  std::string isochrone(const std::string& request_str) {
    return valhalla::tyr::actor_t::isochrone(request_str, nullptr, nullptr);
  };
  std::string trace_route(const std::string& request_str) {
    return valhalla::tyr::actor_t::trace_route(request_str, nullptr, nullptr);
  };
  std::string trace_attributes(const std::string& request_str) {
    return valhalla::tyr::actor_t::trace_attributes(request_str, nullptr, nullptr);
  };
  std::string height(const std::string& request_str) {
    return valhalla::tyr::actor_t::height(request_str, nullptr, nullptr);
  };
  std::string transit_available(const std::string& request_str) {
    return valhalla::tyr::actor_t::transit_available(request_str, nullptr, nullptr);
  };
  std::string expansion(const std::string& request_str) {
    return valhalla::tyr::actor_t::expansion(request_str, nullptr, nullptr);
  };
  std::string centroid(const std::string& request_str) {
    return valhalla::tyr::actor_t::centroid(request_str, nullptr, nullptr);
  };
  std::string status(const std::string& request_str) {
    return valhalla::tyr::actor_t::status(request_str, nullptr, nullptr);
  }
};

PYBIND11_MODULE(_valhalla, m) {
  py::class_<simplified_actor_t>(m, "_Actor")
      .def(py::init<>([](std::string config_file, std::string tile_extract = "", py::dict config = {}, bool verbose = false) {simplified_actor_t actor(configure(config_file, tile_extract, config, verbose)); return actor; }))
      .def("Route", &simplified_actor_t::route, "Calculates a route.")
      .def("Locate", &simplified_actor_t::locate, "Provides information about nodes and edges.")
      .def("OptimizedRoute", &simplified_actor_t::optimized_route,
           "Optimizes the order of a set of waypoints by time.")
      .def(
          "Matrix", &simplified_actor_t::matrix,
          "Computes the time and distance between a set of locations and returns them as a matrix table.")
      .def("Isochrone", &simplified_actor_t::isochrone, "Calculates isochrones and isodistances.")
      .def("TraceRoute", &simplified_actor_t::trace_route,
           "Map-matching for a set of input locations, e.g. from a GPS.")
      .def(
          "TraceAttributes", &simplified_actor_t::trace_attributes,
          "Returns detailed attribution along each portion of a route calculated from a set of input locations, e.g. from a GPS trace.")
      .def("Height", &simplified_actor_t::height,
           "Provides elevation data for a set of input geometries.")
      .def(
          "TransitAvailable", &simplified_actor_t::transit_available,
          "Lookup if transit stops are available in a defined radius around a set of input locations.")
      .def(
          "Expansion", &simplified_actor_t::expansion,
          "Returns all road segments which were touched by the routing algorithm during the graph traversal.")
      .def(
          "Centroid", &simplified_actor_t::centroid,
          "Returns routes from all the input locations to the minimum cost meeting point of those paths.")
      .def("Status", &simplified_actor_t::status,
           "Returns nothing or optionally details about Valhalla's configuration.")
      //.def("RecoverShortcut", &simplified_actor_t::recover_shortcut, "Returns the graph id values for all edges comprising the given shortcut.")
      //.def("GetShorcut", &simplified_actor_t::get_shortcut, "Returns the shortcut's edge ID if the passed edge ID is superseded by a shortcut else 0.")
      ;
}
