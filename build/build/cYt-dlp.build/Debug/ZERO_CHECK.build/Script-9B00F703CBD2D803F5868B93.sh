#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  make -f /Users/czl/Desktop/st/cYt-dlp/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  make -f /Users/czl/Desktop/st/cYt-dlp/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  make -f /Users/czl/Desktop/st/cYt-dlp/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  make -f /Users/czl/Desktop/st/cYt-dlp/build/CMakeScripts/ReRunCMake.make
fi

