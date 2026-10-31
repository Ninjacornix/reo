#import <Foundation/Foundation.h>
#import <Security/Security.h>
#include <cstdio>

// Secrets travel only through a private pipe to the launcher, never argv or logs.
int main(int argc, char** argv) {
    @autoreleasepool {
        if (argc != 3) return 2;
        NSString* identity = [NSString stringWithFormat:@"%s\n%s", argv[1], argv[2]];
        NSDictionary* query = @{(__bridge id)kSecClass:(__bridge id)kSecClassGenericPassword,
            (__bridge id)kSecAttrService:@"net.ninjacornix.reo.network",
            (__bridge id)kSecAttrAccount:identity,
            (__bridge id)kSecReturnData:@YES};
        CFTypeRef found = nullptr;
        OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)query, &found);
        NSData* data = nil;
        if (status == errSecSuccess) data = CFBridgingRelease(found);
        else if (status == errSecItemNotFound) {
            const char* alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
            char bytes[15];
            for (auto& byte : bytes) byte = alphabet[arc4random_uniform(36)];
            data = [NSData dataWithBytes:bytes length:sizeof bytes];
            NSMutableDictionary* add = [query mutableCopy];
            [add removeObjectForKey:(__bridge id)kSecReturnData];
            add[(__bridge id)kSecValueData] = data;
            status = SecItemAdd((__bridge CFDictionaryRef)add, nullptr);
            memset(bytes, 0, sizeof bytes);
        }
        if (status != errSecSuccess || data.length != 15) {
            fprintf(stderr, "Cannot access the saved network credential (Keychain status %d).\n", int(status));
            return 1;
        }
        fwrite(data.bytes, 1, data.length, stdout);
        return 0;
    }
}
