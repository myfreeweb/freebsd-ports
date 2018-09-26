Avoid weird jsoncpp segfault
--- libpoolprotocols/stratum/EthStratumClient.cpp.orig	2018-09-25 12:40:51 UTC
+++ libpoolprotocols/stratum/EthStratumClient.cpp
@@ -576,7 +576,7 @@ void EthStratumClient::processReponse(Json::Value& res
 
 	// Retrieve essential values
 	_id = responseObject.get("id", unsigned(0)).asUInt();
-	_isSuccess = responseObject.get("error", Json::Value::null).empty();
+	_isSuccess = !responseObject.isMember("error");
 	_errReason = (_isSuccess ? "" : processError(responseObject));
 	_method = responseObject.get("method", "").asString();
 	_isNotification = (_id == unsigned(0) || _method != "");
