if(DEFINED USM AND (NOT(USM EQUAL 0)))
    message(STATUS "Using the USM variant.")
    set(SOURCE_FILE optimized_wordcloud.cpp)
    set(TARGET_NAME optwordcloud)
else()    
    set(SOURCE_FILE optimized_wordcloud.cpp)
    set(TARGET_NAME optwordcloud)
endif()

set(OPENSSL_ROOT_DIR "${WordCloud_SOURCE_DIR}/utils/openssl")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIBRARY_DIR "${OPENSSL_ROOT_DIR}/lib64")
set(BLOOM_ROOT_DIR "${WordCloud_SOURCE_DIR}/bloom")
set(COMPILE_FLAGS "-fsycl -Wall ${WIN_FLAG}")
set(LINK_FLAGS "-fsycl")

add_executable(
  wordcloud
  wordcloud.cpp
)

add_executable(
  optwordcloud
  optimized_wordcloud.cpp
)

target_include_directories(wordcloud PUBLIC ${OPENSSL_INCLUDE_DIR})
target_include_directories(wordcloud PUBLIC ${BLOOM_ROOT_DIR})

target_include_directories(optwordcloud PUBLIC ${OPENSSL_INCLUDE_DIR})
target_include_directories(optwordcloud PUBLIC ${BLOOM_ROOT_DIR})

set_target_properties(${TARGET_NAME} PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS}")
set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS "${LINK_FLAGS}")
add_custom_target(cpu-gpu DEPENDS ${TARGET_NAME})


target_link_libraries(
wordcloud
${OPENSSL_LIBRARY_DIR}/libssl.so.3 ${OPENSSL_LIBRARY_DIR}/libcrypto.so.3
)

