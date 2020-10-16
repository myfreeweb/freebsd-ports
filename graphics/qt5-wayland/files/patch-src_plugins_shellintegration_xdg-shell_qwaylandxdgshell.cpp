--- src/plugins/shellintegration/xdg-shell/qwaylandxdgshell.cpp.orig	2020-10-08 21:07:39 UTC
+++ src/plugins/shellintegration/xdg-shell/qwaylandxdgshell.cpp
@@ -410,6 +410,7 @@ void QWaylandXdgSurface::setPopup(QWaylandWindow *pare
     positioner->set_anchor(QtWayland::xdg_positioner::anchor_top_left);
     positioner->set_gravity(QtWayland::xdg_positioner::gravity_bottom_right);
     positioner->set_size(m_window->geometry().width(), m_window->geometry().height());
+    positioner->set_constraint_adjustment(QtWayland::xdg_positioner::constraint_adjustment_slide_x | QtWayland::xdg_positioner::constraint_adjustment_slide_y | QtWayland::xdg_positioner::constraint_adjustment_flip_x | QtWayland::xdg_positioner::constraint_adjustment_flip_y);
     m_popup = new Popup(this, parentXdgSurface, positioner);
     positioner->destroy();
     delete positioner;
