#import <Cocoa/Cocoa.h>
#import <QuartzCore/CAMetalLayer.h>
#import <objc/runtime.h>
#include <stdexcept>
#include "../../../runtime/input/macos_input.h"

@interface ReoMetalView : NSView
@end
@implementation ReoMetalView
- (CALayer*)makeBackingLayer {
    return [CAMetalLayer layer];
}
@end

// Called only by the window thread. The GS worker receives a layer pointer,
// never an NSWindow, and does not dispatch synchronously back to the UI thread.
void* reoMetalLayerForWindow(void* nativeWindow, int width, int height) {
    if (![NSThread isMainThread])
        throw std::runtime_error("Metal view creation must run on the main thread");
    if (!nativeWindow)
        return nullptr;
    @autoreleasepool {
        reo::macos_input::capture();
        NSWindow* window = (__bridge NSWindow*)nativeWindow;
        static char viewKey;
        ReoMetalView* view = objc_getAssociatedObject(window, &viewKey);
        if (!view) {
            view = [[ReoMetalView alloc] initWithFrame:window.contentView.bounds];
            view.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
            view.wantsLayer = YES;
            [window.contentView addSubview:view];
            objc_setAssociatedObject(window, &viewKey, view, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        }
        CAMetalLayer* layer = (CAMetalLayer*)view.layer;
        layer.opaque = YES;
        layer.framebufferOnly = YES;
        layer.contentsScale = window.backingScaleFactor;
        if (width > 0 && height > 0)
            layer.drawableSize = CGSizeMake(width, height);
        return (__bridge void*)layer;
    }
}
