"var cookie_namespace = 'doxygen'; \n"
"var sidenav,navtree,content,header;\n"
"\n"
"function readCookie(cookie) \n"
"{\n"
"  var myCookie = cookie_namespace+\"_\"+cookie+\"=\";\n"
"  if (document.cookie) \n"
"  {\n"
"    var index = document.cookie.indexOf(myCookie);\n"
"    if (index != -1) \n"
"    {\n"
"      var valStart = index + myCookie.length;\n"
"      var valEnd = document.cookie.indexOf(\";\", valStart);\n"
"      if (valEnd == -1) \n"
"      {\n"
"        valEnd = document.cookie.length;\n"
"      }\n"
"      var val = document.cookie.substring(valStart, valEnd);\n"
"      return val;\n"
"    }\n"
"  }\n"
"  return 0;\n"
"}\n"
"\n"
"function writeCookie(cookie, val, expiration) \n"
"{\n"
"  if (val==undefined) return;\n"
"  if (expiration == null) \n"
"  {\n"
"    var date = new Date();\n"
"    date.setTime(date.getTime()+(10*365*24*60*60*1000)); // default expiration is one week\n"
"    expiration = date.toGMTString();\n"
"  }\n"
"  document.cookie = cookie_namespace + \"_\" + cookie + \"=\" + val + \"; expires=\" + expiration+\"; path=/\";\n"
"}\n"
" \n"
"function resizeWidth() \n"
"{\n"
"  var windowWidth = $(window).width() + \"px\";\n"
"  var sidenavWidth = $(sidenav).outerWidth();\n"
"  content.css({marginLeft:parseInt(sidenavWidth)+6+\"px\"}); //account for 6px-wide handle-bar\n"
"  writeCookie('width',sidenavWidth, null);\n"
"}\n"
"\n"
"function restoreWidth(navWidth)\n"
"{\n"
"  var windowWidth = $(window).width() + \"px\";\n"
"  content.css({marginLeft:parseInt(navWidth)+6+\"px\"});\n"
"  sidenav.css({width:navWidth + \"px\"});\n"
"}\n"
"\n"
"function resizeHeight() \n"
"{\n"
"  var headerHeight = header.outerHeight();\n"
"  var footerHeight = footer.outerHeight();\n"
"  var windowHeight = $(window).height() - headerHeight - footerHeight;\n"
"  content.css({height:windowHeight + \"px\"});\n"
"  navtree.css({height:windowHeight + \"px\"});\n"
"  sidenav.css({height:windowHeight + \"px\",top: headerHeight+\"px\"});\n"
"}\n"
"\n"
"function initResizable()\n"
"{\n"
"  header  = $(\"#top\");\n"
"  sidenav = $(\"#side-nav\");\n"
"  content = $(\"#doc-content\");\n"
"  navtree = $(\"#nav-tree\");\n"
"  footer  = $(\"#nav-path\");\n"
"  $(\".side-nav-resizable\").resizable({resize: function(e, ui) { resizeWidth(); } });\n"
"  $(window).resize(function() { resizeHeight(); });\n"
"  var width = readCookie('width');\n"
"  if (width) { restoreWidth(width); } else { resizeWidth(); }\n"
"  resizeHeight();\n"
"  var url = location.href;\n"
"  var i=url.indexOf(\"#\");\n"
"  if (i>=0) window.location.hash=url.substr(i);\n"
"  var _preventDefault = function(evt) { evt.preventDefault(); };\n"
"  $(\"#splitbar\").bind(\"dragstart\", _preventDefault).bind(\"selectstart\", _preventDefault);\n"
"  $(document).bind('touchmove',function(e){\n"
"    try {\n"
"      var target = e.target;\n"
"      while (target) {\n"
"        if ($(target).css('-webkit-overflow-scrolling')=='touch') return;\n"
"        target = target.parentNode;\n"
"      }\n"
"      e.preventDefault();\n"
"    } catch(err) {\n"
"      e.preventDefault();\n"
"    }\n"
"  });\n"
"}\n"
"\n"
"\n"
