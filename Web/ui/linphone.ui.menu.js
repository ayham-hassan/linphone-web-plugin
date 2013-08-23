/*!
 Linphone Web - Web plugin of Linphone an audio/video SIP phone
 Copyright (c) 2013 Belledonne Communications
 All rights reserved.
 

 Authors:
 - Yann Diorcet <diorcet.yann@gmail.com>
 
 */

/*globals jQuery,linphone*/

linphone.ui.menu = {
		populateLocalesMenu : function(base) {
		// Locales
		var menu = base.find('.window .tools .locales-menu');
		menu.empty();
		for ( var index in linphone.ui.locales) {
			var item = linphone.ui.locales[index];
			var element = jQuery(base.find('.templates .Linphone-LocaleItem').render(item));
			element.find('a').data('data', item);
			menu.append(element);
		}
		menu.menu();
	}
};

// OnLoad
jQuery(function() {
	jQuery('.linphone .window .tools .settings-menu').menu();

	jQuery('.linphone .window .tools .video-menu').menu();
});

// Click
jQuery('html').click(function(event) {
	var target = jQuery(event.target ? event.target : event.srcElement);
	var base = linphone.ui.getBase(target);

	// Click on settings
	if (target.is('.linphone .window .tools .settings-icon')) {
		base.find('.window .tools .settings-menu').fadeToggle('fast');
	} else if (target.parents(".linphone .window .tools .settings-icon").length === 0) {
		jQuery('.linphone .window .tools .settings-menu').fadeOut('fast');
	}
});
