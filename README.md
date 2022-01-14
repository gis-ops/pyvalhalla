# Changelog for patches in this version

Apply each patch file to see the actual code changes.

- `custom_eclever_actor`: implement `get_shortcut` & `recover_shortcut` in Actor interface and expose in bindings
- `custom_eclever_trace_serializer`: 
  - (**eventually PR**) `source/target_percent_along` response fields were added and can be used to retrieve the actual position of the correlated point
  - slim down the trace_attributes response to only needed fields
- `custom_eclever_locate_serializer`: slim down the /locate response to only needed fields
