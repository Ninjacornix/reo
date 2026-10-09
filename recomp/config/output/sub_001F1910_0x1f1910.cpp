#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1910
// Address: 0x1f1910 - 0x1f19c0
void sub_001F1910_0x1f1910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1910_0x1f1910");
#endif

    switch (ctx->pc) {
        case 0x1f1958u: goto label_1f1958;
        case 0x1f1988u: goto label_1f1988;
        default: break;
    }

    ctx->pc = 0x1f1910u;

    // 0x1f1910: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f1910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1914: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1918: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f191c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f191cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1920: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f1920u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1924: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f1924u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f1928: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1f1928u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f192c: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x1f192cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1930: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1f1930u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1934: 0xa7c3000a  sh          $v1, 0xA($fp)
    ctx->pc = 0x1f1934u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f1938: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1f1938u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1f193c: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f193cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1940: 0x97c3000a  lhu         $v1, 0xA($fp)
    ctx->pc = 0x1f1940u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 10)));
    // 0x1f1944: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f1944u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1948: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f1948u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f194c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1f194cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1950: 0xc07c61c  jal         func_1F1870
    ctx->pc = 0x1F1950u;
    SET_GPR_U32(ctx, 31, 0x1F1958u);
    ctx->pc = 0x1F1870u;
    if (runtime->hasFunction(0x1F1870u)) {
        auto targetFn = runtime->lookupFunction(0x1F1870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1958u; }
        if (ctx->pc != 0x1F1958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1870_0x1f1870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1958u; }
        if (ctx->pc != 0x1F1958u) { return; }
    }
    ctx->pc = 0x1F1958u;
label_1f1958:
    // 0x1f1958: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1958u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f195c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f195cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1960: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1960u;
    {
        const bool branch_taken_0x1f1960 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1960) {
            ctx->pc = 0x1F1974u;
            goto label_1f1974;
        }
    }
    ctx->pc = 0x1F1968u;
    // 0x1f1968: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1968u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f196c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1F196Cu;
    {
        const bool branch_taken_0x1f196c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f196c) {
            ctx->pc = 0x1F19A8u;
            goto label_1f19a8;
        }
    }
    ctx->pc = 0x1F1974u;
label_1f1974:
    // 0x1f1974: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f1974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1978: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f1978u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f197c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1f197cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1980: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1F1980u;
    SET_GPR_U32(ctx, 31, 0x1F1988u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1988u; }
        if (ctx->pc != 0x1F1988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1988u; }
        if (ctx->pc != 0x1F1988u) { return; }
    }
    ctx->pc = 0x1F1988u;
label_1f1988:
    // 0x1f1988: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1988u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f198c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f198cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1990: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1990u;
    {
        const bool branch_taken_0x1f1990 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1990) {
            ctx->pc = 0x1F19A4u;
            goto label_1f19a4;
        }
    }
    ctx->pc = 0x1F1998u;
    // 0x1f1998: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f199c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F199Cu;
    {
        const bool branch_taken_0x1f199c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f199c) {
            ctx->pc = 0x1F19A8u;
            goto label_1f19a8;
        }
    }
    ctx->pc = 0x1F19A4u;
label_1f19a4:
    // 0x1f19a4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f19a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1f19a8:
    // 0x1f19a8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f19a8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f19ac: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f19acu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f19b0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f19b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f19b4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f19b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f19b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F19B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1958u: goto label_1f1958;
            case 0x1F1974u: goto label_1f1974;
            case 0x1F1988u: goto label_1f1988;
            case 0x1F19A4u: goto label_1f19a4;
            case 0x1F19A8u: goto label_1f19a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F19C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
