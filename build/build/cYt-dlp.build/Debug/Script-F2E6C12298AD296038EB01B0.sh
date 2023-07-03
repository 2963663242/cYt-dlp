#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/
  cp -r -p /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/* /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/
  cp -r -p /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/* /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/
  cp -r -p /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/* /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/czl/Desktop/st/cYt-dlp/build
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
  chmod -R 755 /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/
  cp -r -p /Users/czl/Desktop/st/cYt-dlp/sdk/mac/bin/* /Users/czl/Desktop/st/cYt-dlp/build/x64/Debug
fi

