
#ifndef CONFIG_COMPARE_REST_SERVER_H
#define CONFIG_COMPARE_REST_SERVER_H

#include <restinio/all.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string>

void run_rest_server(const int port, const std::string& address);
std::string decode_jwt(const std::string& jwt_string);
restinio::request_handling_status_t handler(restinio::request_handle_t req);


#endif //CONFIG_COMPARE_REST_SERVER_H
