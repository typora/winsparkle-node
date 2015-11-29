#include <node.h>
#include <string>
#include "winsparkle.h"

namespace nodesparkle {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void _win_sparkle_cleanup(const FunctionCallbackInfo<Value>& args) {
	  	win_sparkle_cleanup();
	}

	void _win_sparkle_set_appcast_url(const FunctionCallbackInfo<Value>& args) {
	  	std::string url(*v8::String::Utf8Value(args[0]));
	  	win_sparkle_set_appcast_url(url.c_str());
	}

	void _win_sparkle_check_update_with_ui(const FunctionCallbackInfo<Value>& args) {
	  	win_sparkle_check_update_with_ui();
	}

	void _win_sparkle_init(const FunctionCallbackInfo<Value>& args) {
	  	win_sparkle_init();
	}

	void init(Local<Object> exports) {
	  	NODE_SET_METHOD(exports, "winSparkleCleanup", _win_sparkle_cleanup);
	  	NODE_SET_METHOD(exports, "winSparkleSetAppcastUrl", _win_sparkle_set_appcast_url);
	  	NODE_SET_METHOD(exports, "winSparkleCheckUpdateWithUI", _win_sparkle_check_update_with_ui);
	  	NODE_SET_METHOD(exports, "winSparkleInit", _win_sparkle_init);
	}

	NODE_MODULE(addon, init)

}  
