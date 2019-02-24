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
	
	void _win_sparkle_set_lang(const FunctionCallbackInfo<Value>& args) {
	  	std::string lang(*v8::String::Utf8Value(args[0]));
	  	win_sparkle_set_lang(lang.c_str());
	}

	void _win_sparkle_check_update_with_ui(const FunctionCallbackInfo<Value>& args) {
	  	win_sparkle_check_update_with_ui();
	}

	void _win_sparkle_check_update_without_ui(const FunctionCallbackInfo<Value>& args) {
	  	win_sparkle_check_update_without_ui();
	}

	void _win_sparkle_init(const FunctionCallbackInfo<Value>& args) {
	  	win_sparkle_init();
	}

	void _win_sparkle_set_automatic_check_for_updates(const FunctionCallbackInfo<Value>& args) {
		int state = ((bool) args[0]->BooleanValue()) ? 1 : 0;
	  	win_sparkle_set_automatic_check_for_updates(state);
	}

	void _win_sparkle_get_automatic_check_for_updates(const FunctionCallbackInfo<Value>& args) {
	  	int state = win_sparkle_get_automatic_check_for_updates();
	  	Isolate* isolate = args.GetIsolate();
  		args.GetReturnValue().Set(v8::Boolean::New(isolate, state > 0));
	}


	void init(Local<Object> exports) {
	  	NODE_SET_METHOD(exports, "winSparkleCleanup", _win_sparkle_cleanup);
	  	NODE_SET_METHOD(exports, "winSparkleSetAppcastUrl", _win_sparkle_set_appcast_url);
		NODE_SET_METHOD(exports, "winSparkleSetLang", _win_sparkle_set_lang);
	  	NODE_SET_METHOD(exports, "winSparkleCheckUpdateWithUI", _win_sparkle_check_update_with_ui);
	  	NODE_SET_METHOD(exports, "winSparkleCheckUpdateWithoutUI", _win_sparkle_check_update_without_ui);
	  	NODE_SET_METHOD(exports, "winSparkleInit", _win_sparkle_init);
	  	NODE_SET_METHOD(exports, "winSparkleSetAutomaticCheckForUpdates", _win_sparkle_set_automatic_check_for_updates);
	  	NODE_SET_METHOD(exports, "winSparkleGetAutomaticCheckForUpdates", _win_sparkle_get_automatic_check_for_updates);
	}

	NODE_MODULE(addon, init)

}  
