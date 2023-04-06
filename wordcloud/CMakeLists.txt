set(OPENSSL_ROOT_DIR "/home/runner/Special-Team-Bloom-Filter-comp-339-439-ds/utils/openssl")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIBRARY_DIR "${OPENSSL_ROOT_DIR}/lib64")
set(BLOOM_ROOT_DIR "/home/runner/Special-Team-Bloom-Filter-comp-339-439-ds/bloom")

add_executable(
  wordcloud
  wordcloud.cpp
)

target_include_directories(wordcloud PUBLIC ${OPENSSL_INCLUDE_DIR})
target_include_directories(wordcloud PUBLIC ${BLOOM_ROOT_DIR})

target_link_libraries(
wordcloud
${OPENSSL_LIBRARY_DIR}/libssl.so.3 ${OPENSSL_LIBRARY_DIR}/libcrypto.so.3
)