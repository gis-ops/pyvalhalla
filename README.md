# Changelog for patches in this version

Apply each patch file to see the actual code changes.

- `custom_eclever_actor`: 
  - implement `get_livespeed` in Actor interface and expose in bindings
  - implement `get_edge_speed` in Actor & GraphReader interface to retrieve non-live speed for an edge ID
  - implement `recover_all_shortcuts` in Actor & GraphReader, needed lots of adjustments on `shortcut_recovery_t`
- `custom_eclever_trace_serializer`: 
  - (**eventually PR**) `source/target_percent_along` response fields were added and can be used to retrieve the actual position of the correlated point
  - added `total_length` in response to return an edge's total length
  - slim down the trace_attributes response to only needed fields
- `custom_eclever_locate_serializer`: slim down the /locate response to only needed fields
- ~~`custom_eclever_service`: add the `get_livespeed` to `valhalla_service` on command line~~
