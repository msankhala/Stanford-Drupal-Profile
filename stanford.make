; This file was auto-generated by drush_make
core = 7.x

api = 2
projects[drupal][version] = "7.12"

; Contributed modules
projects[admin_menu][version] = "3.0-rc1"
projects[auto_nodetitle][version] = "1.0"
projects[ctools][version] = "1.0"
projects[calendar][version] = "3.0-alpha2"
projects[css_injector][version] = "1.7"
projects[date][version] = "2.0-rc1"
projects[email][version] = "1.0"
projects[features][version] = "1.0-rc1"
projects[globalredirect][version] = "1.4"
projects[insert][version] = "1.1"
projects[link][version] = "1.0"
projects[nodeformcols][version] = "1.x-dev"
projects[pathauto][version] = "1.0"
projects[pathologic][version] = "1.4"
projects[semanticviews][version] = "1.x-dev"
projects[token][version] = "1.0-rc1"
projects[views][version] = "3.3"
projects[wysiwyg][version] = "2.1"

; Contributed themes
projects[rubik][version] = "4.0-beta7"
projects[tao][version] = "3.0-beta4"

; Custom modules, github
projects[stanford_sites_systemtools][type] = "module"
projects[stanford_sites_systemtools][download][type] = "git"
projects[stanford_sites_systemtools][download][url] = "git@github.com:SU-SWS/SU-IT-Services.git"
; projects[stanford_sites_systemtools][download][url] = "file:///home/quickstart/Documents/stanford_sites_systemtools"
projects[stanford_sites_systemtools][download][tag] = "7.x-1.0-alpha2"
projects[stanford_sites_helper][type] = "module"
projects[stanford_sites_helper][download][type] = "git"
projects[stanford_sites_helper][download][url] = "git@github.com:SU-SWS/stanford_sites_helper.git"
; projects[stanford_sites_helper][download][url] = "file:///home/quickstart/Documents/stanford_sites_helper"
projects[stanford_sites_helper][download][tag] = "7.x-1.0-alpha2"

; Custom themes, github
projects[stanfordmodern][type] = theme
projects[stanfordmodern][download][type] = git
projects[stanfordmodern][download][url] = git@github.com:su-ddd/stanfordmodern.git
projects[stanfordmodern][tag] = "7.x-1.0"
projects[stanford_basic][type] = theme
projects[stanford_basic][download][type] = git
projects[stanford_basic][download][url] = git@github.com:su-ddd/stanford_basic.git
projects[stanford_basic][download][branch] = "7.x-1.x"

; Custom themes, github
; disabled until D7 versions released
;projects[stanford_framework][type] = theme
;projects[stanford_framework][version] = "6.x-1.01"
;projects[stanford_framework][download][type] = git
;projects[stanford_framework][download][url] = git@github.com:SU-SWS/stanford_framework.git

; Custom modules, Stanford features server
projects[webauth][location] = "http://drupalfeatures.stanford.edu/fserver"
projects[webauth][version] = "3.0"


; Profile

projects[stanford][type] = "profile"
projects[stanford][download][type] = "git"
projects[stanford][download][url] = "git@github.com:SU-SWS/Stanford-Drupal-Profile.git"
; projects[stanford][download][url] = "file:///home/quickstart/Documents/D7/Stanford-Drupal-Profile"
; projects[stanford][download][tag] = 7.x-1.0-alpha7
projects[stanford][download][branch] = 7.x-1.x
