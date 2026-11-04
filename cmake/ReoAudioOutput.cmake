# Keep upstream sources untouched and fail closed when the reviewed call sites change.
function(reo_audio_output_source source output)
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    get_filename_component(_reo_root "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/.." ABSOLUTE)
    execute_process(COMMAND "${Python3_EXECUTABLE}" "${_reo_root}/tools/local_build/prepare_audio_output.py"
        "${source}" "${output}" RESULT_VARIABLE _reo_result)
    if(NOT _reo_result EQUAL 0)
        message(FATAL_ERROR "Could not prepare the reviewed per-game audio output provider")
    endif()
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
        "${source}" "${_reo_root}/tools/local_build/prepare_audio_output.py")
endfunction()
