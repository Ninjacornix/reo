#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1870
// Address: 0x1f1870 - 0x1f1910
void sub_001F1870_0x1f1870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1870_0x1f1870");
#endif

    switch (ctx->pc) {
        case 0x1f18a4u: goto label_1f18a4;
        default: break;
    }

    ctx->pc = 0x1f1870u;

    // 0x1f1870: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f1870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1874: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1878: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f187c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f187cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1880: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f1880u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f1884: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f1884u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1888: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1f1888u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f188c: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1f188cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1890: 0xa7c30006  sh          $v1, 0x6($fp)
    ctx->pc = 0x1f1890u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 6), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f1894: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1f1894u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1898: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f1898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f189c: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1F189Cu;
    SET_GPR_U32(ctx, 31, 0x1F18A4u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F18A4u; }
        if (ctx->pc != 0x1F18A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F18A4u; }
        if (ctx->pc != 0x1F18A4u) { return; }
    }
    ctx->pc = 0x1F18A4u;
label_1f18a4:
    // 0x1f18a4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f18a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f18a8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f18a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f18ac: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F18ACu;
    {
        const bool branch_taken_0x1f18ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f18ac) {
            ctx->pc = 0x1F18C0u;
            goto label_1f18c0;
        }
    }
    ctx->pc = 0x1F18B4u;
    // 0x1f18b4: 0x2402e4a9  addiu       $v0, $zero, -0x1B57
    ctx->pc = 0x1f18b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960297));
    // 0x1f18b8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1F18B8u;
    {
        const bool branch_taken_0x1f18b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f18b8) {
            ctx->pc = 0x1F18F8u;
            goto label_1f18f8;
        }
    }
    ctx->pc = 0x1F18C0u;
label_1f18c0:
    // 0x1f18c0: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f18c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f18c4: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1f18c4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f18c8: 0xa4620008  sh          $v0, 0x8($v1)
    ctx->pc = 0x1f18c8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f18cc: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f18ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f18d0: 0x97c20006  lhu         $v0, 0x6($fp)
    ctx->pc = 0x1f18d0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 6)));
    // 0x1f18d4: 0xa462000a  sh          $v0, 0xA($v1)
    ctx->pc = 0x1f18d4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f18d8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f18d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f18dc: 0xa440000e  sh          $zero, 0xE($v0)
    ctx->pc = 0x1f18dcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f18e0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f18e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f18e4: 0xa440000c  sh          $zero, 0xC($v0)
    ctx->pc = 0x1f18e4u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 12), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f18e8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f18e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f18ec: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f18ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f18f0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f18f0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f18f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f18f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f18f8:
    // 0x1f18f8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f18f8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f18fc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f18fcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f1900: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f1900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f1904: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f1904u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1908: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F18A4u: goto label_1f18a4;
            case 0x1F18C0u: goto label_1f18c0;
            case 0x1F18F8u: goto label_1f18f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
