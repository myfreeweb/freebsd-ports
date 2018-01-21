--- lib/efi_loader/efi_net.c.orig	2018-01-20 14:36:17 UTC
+++ lib/efi_loader/efi_net.c
@@ -87,7 +87,8 @@ static efi_status_t EFIAPI efi_net_receive_filters(
 	EFI_ENTRY("%p, %x, %x, %x, %lx, %p", this, enable, disable,
 		  reset_mcast_filter, mcast_filter_count, mcast_filter);
 
-	return EFI_EXIT(EFI_UNSUPPORTED);
+	printf("%s: WARNING - unsupported but returning success\n", __func__);
+	return EFI_EXIT(EFI_SUCCESS);
 }
 
 static efi_status_t EFIAPI efi_net_station_address(
