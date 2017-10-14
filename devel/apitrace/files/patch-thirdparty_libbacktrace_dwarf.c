--- thirdparty/libbacktrace/dwarf.c.orig	2017-10-05 14:14:11 UTC
+++ thirdparty/libbacktrace/dwarf.c
@@ -1851,10 +1851,6 @@ read_line_program (struct backtrace_state *state, stru
 		  }
 	      }
 	      break;
-	    case DW_LNE_set_discriminator:
-	      /* We don't care about discriminators.  */
-	      read_uleb128 (line_buf);
-	      break;
 	    default:
 	      if (!advance (line_buf, len - 1))
 		return 0;
