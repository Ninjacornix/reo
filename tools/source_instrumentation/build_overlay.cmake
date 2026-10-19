# Build-directory source rewriting only. Public Context/PCH and canonical
# generated instruction files are not regenerated or edited.
set(REO_SOURCE_INSTRUMENTER "" CACHE FILEPATH "Built reviewed source instrumenter")
function(reo_emit_guarded_sources result)
    if(NOT ARGN)
        set(${result} "" PARENT_SCOPE)
        return()
    endif()
    if(NOT EXISTS "${REO_SOURCE_INSTRUMENTER}")
        message(FATAL_ERROR "Guarded source overlay requires reviewed REO_SOURCE_INSTRUMENTER")
    endif()
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    if(REO_GUARDED_SOURCE_MODULE_DIR)
        set(_source_module "${REO_GUARDED_SOURCE_MODULE_DIR}")
    else()
        set(_source_module "${CMAKE_CURRENT_SOURCE_DIR}/../tools/source_instrumentation")
    endif()
    set(_overlay "${CMAKE_CURRENT_BINARY_DIR}/guarded/${TARGET_NAME}/${result}")
    file(MAKE_DIRECTORY "${_overlay}")
    string(REPLACE ";" "\n" _input_text "${ARGN}")
    file(WRITE "${_overlay}/sources.txt" "${_input_text}\n")
    execute_process(COMMAND "${Python3_EXECUTABLE}" "${_source_module}/emit_overlay.py"
        --tool "${REO_SOURCE_INSTRUMENTER}" --output "${_overlay}"
        --sources "${_overlay}/sources.txt"
        RESULT_VARIABLE _emitted OUTPUT_VARIABLE _summary ERROR_VARIABLE _error)
    if(NOT _emitted EQUAL 0)
        message(FATAL_ERROR "Guarded source overlay declined before compilation: ${_error}")
    endif()
    include("${_overlay}/emitted.cmake")
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${ARGN}
        "${REO_SOURCE_INSTRUMENTER}" "${_source_module}/emit_overlay.py")
    set(${result} ${REO_EMITTED_SOURCES} PARENT_SCOPE)
    message(STATUS "${_summary}")
endfunction()
