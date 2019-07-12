
#include <iostream>

#include <restinio/all.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string>
#include <sstream>
#include <utility>

#include <regex>

#include "rest_server.h"
#include "file_comparison.h"
#include "jwt/jwt.hpp"

void run_rest_server(const int port, const std::string& address)
{

	using namespace std::chrono;

	try
	{

		restinio::run(
			restinio::on_this_thread()
				.port( port )
				.address( address )
				.request_handler( handler ) );
	}
	catch( const std::exception & ex )
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return;
	}

}

std::string decode_jwt(const std::string& jwt_string)
{

	using namespace jwt::params;

	auto key = "UsZrRgstPVWiMPydZeeH1w1wkna62XME"; //Secret to use for the algorithm
	//Create JWT object
	// jwt::jwt_object obj{algorithm("HS256"), payload({{"run", "scan"}}), secret(key)};

	//Get the encoded string/assertion
	// auto enc_str = obj.signature();
	// std::cout << enc_str << std::endl;

	//Decode
	auto dec_obj = jwt::decode(jwt_string, algorithms({"hs256"}), secret(key));
	// std::cout << dec_obj.header() << std::endl;
	// std::cout << dec_obj.payload() << std::endl;

	std::stringstream sstream;
	sstream << dec_obj.payload();

	// return std::make_pair<std::string, std::string>(dec_obj.header(), dec_obj.payload());
	return sstream.str();

}

restinio::request_handling_status_t handler(restinio::request_handle_t req)
{

	std::regex r("^/[A-Za-z0-9-_=]+\\.[A-Za-z0-9-_=]+\\.?[A-Za-z0-9-_.+/=]*$");

	std::cout << "Connection received" << std::endl;

	if (restinio::http_method_get() == req->header().method() &&
		std::regex_match(req->header().request_target(), r))
	{

		std::cout << "GET target proper" << std::endl;
		std::string target = req->header().request_target().substr(1);
		std::string dec = decode_jwt(target);
		
		std::string s;

		if (dec == "{\"run\":\"scan\"}")
		{

			// run scan files
			std::cout << "running scan files" << std::endl;
			//s = "Run scan files";
			// s = "{\"scans\":[{\"type\":\"SSH\",\"files\":[{\"name\":\"/etc/ssh/sshd_config\",\"J\":\".578\"}]}]}";
			s = do_comparisons();
			std::cout << s << std::endl;

		} else {
			std::cout << dec << std::endl << "Issue" << std::endl;
		}

		req->create_response()
	      .append_header( restinio::http_field::server, "Bee Server" )
	      .append_header_date_field()
	      .append_header( restinio::http_field::content_type, "text/json; charset=utf-8" )
	      .set_body(s)
	      .done();
	    return restinio::request_accepted();
	}

	return restinio::request_rejected();

}
