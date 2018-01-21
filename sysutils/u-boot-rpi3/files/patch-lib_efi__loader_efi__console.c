--- lib/efi_loader/efi_console.c.orig	2018-01-20 20:03:19 UTC
+++ lib/efi_loader/efi_console.c
@@ -539,8 +539,8 @@ int efi_console_register(void)
 		printf("ERROR: Failed to register console event\n");
 		return r;
 	}
-	/* 5000 ns cycle is sufficient for 2 MBaud */
-	r = efi_set_timer(console_timer_event, EFI_TIMER_PERIODIC, 50);
+	/* 100 ms cycle is sufficient for user input and does not slow down network boot */
+	r = efi_set_timer(console_timer_event, EFI_TIMER_PERIODIC, 100*1000*10);
 	if (r != EFI_SUCCESS)
 		printf("ERROR: Failed to set console timer\n");
 	return r;
