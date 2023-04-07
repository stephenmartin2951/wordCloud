set(OPENSSL_ROOT_DIR "${WordCloud_SOURCE_DIR}/utils/openssl")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIBRARY_DIR "${OPENSSL_ROOT_DIR}/lib64")

add_executable(
  bloomfilter
  bloomfilter.cpp
)


target_include_directories(bloomfilter PUBLIC ${OPENSSL_INCLUDE_DIR})

target_link_libraries(
bloomfilter
${OPENSSL_LIBRARY_DIR}/libssl.so.3 ${OPENSSL_LIBRARY_DIR}/libcrypto.so.3
)