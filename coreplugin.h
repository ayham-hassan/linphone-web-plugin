/*!
 Linphone Web - Web plugin of Linphone an audio/video SIP phone
 Copyright (C) 2012  Yann Diorcet <yann.diorcet@linphone.org>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef H_COREPLUGIN
#define H_COREPLUGIN

#include <PluginWindow.h>
#include <PluginEvents/MouseEvents.h>
#include <PluginEvents/AttachedEvent.h>
#include <PluginCore.h>

#include <ortp/logging.h>

FB_FORWARD_PTR(core)
class core: public FB::PluginCore {
private:
#ifdef DEBUG
	static FILE *s_log_file;
	static void log(OrtpLogLevel lev, const char *fmt, va_list args);
	static void enableLog();
#endif
	static void disableLog();
public:
	static void StaticInitialize();
	static void StaticDeinitialize();

public:
	core();
	virtual ~core();

public:
	void onPluginReady();
	virtual bool setReady();
	void shutdown();
	virtual FB::JSAPIPtr createJSAPI();
	// If you want your plugin to always be windowless, set this to true
	// If you want your plugin to be optionally windowless based on the
	// value of the "windowless" param tag, remove this method or return
	// FB::PluginCore::isWindowless()
	virtual bool isWindowless() {
		return true;
	}
	virtual void 	setFSPath (const std::string &path);

	BEGIN_PLUGIN_EVENT_MAP()
	EVENTTYPE_CASE(FB::MouseDownEvent, onMouseDown, FB::PluginWindow)
	EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindow)
	EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
	EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
	EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
	EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
	END_PLUGIN_EVENT_MAP()

	/** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
	virtual bool onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *);
	virtual bool onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *);
	virtual bool onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *);
	virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *);
	virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *);
	/** END EVENTDEF -- DON'T CHANGE THIS LINE **/
};

#endif //H_COREPLUGIN
