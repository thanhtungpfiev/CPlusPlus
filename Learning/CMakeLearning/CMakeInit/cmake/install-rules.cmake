install(
    TARGETS CMakeInit_exe
    RUNTIME COMPONENT CMakeInit_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
