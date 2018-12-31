--- src/text/ptbl/xp/pd_DocumentRDF.cpp.orig	2018-11-03 20:28:18 UTC
+++ src/text/ptbl/xp/pd_DocumentRDF.cpp
@@ -2269,8 +2269,8 @@ PD_RDFEvent::exportToFile( const std::string& filename
         icalcomponent_set_uid( c,         m_uid.c_str() );
         icalcomponent_set_location( c,    m_location.c_str() );
         icalcomponent_set_description( c, m_desc.c_str() );
-        icalcomponent_set_dtstart( c,     icaltime_from_timet( m_dtstart, 0 ) );
-        icalcomponent_set_dtend( c,       icaltime_from_timet( m_dtend, 0 ) );
+        icalcomponent_set_dtstart( c,     icaltime_from_timet_with_zone( m_dtstart, 0, NULL ) );
+        icalcomponent_set_dtend( c,       icaltime_from_timet_with_zone( m_dtend, 0, NULL ) );
 
         char* data = icalcomponent_as_ical_string( c );
         std::ofstream oss( filename.c_str() );
