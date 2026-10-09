#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F357C
// Address: 0x1f357c - 0x1f3610
void sub_001F357C_0x1f357c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F357C_0x1f357c");
#endif

    switch (ctx->pc) {
        case 0x1f35acu: goto label_1f35ac;
        case 0x1f35ccu: goto label_1f35cc;
        case 0x1f35e0u: goto label_1f35e0;
        case 0x1f35f4u: goto label_1f35f4;
        default: break;
    }

    ctx->pc = 0x1f357cu;

    // 0x1f357c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f357cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f3580: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f3580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f3584: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f3584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f3588: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3588u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f358c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f358cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3590: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f3590u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f3594: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f3594u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f3598: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f3598u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f359c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f359cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f35a0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f35a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f35a4: 0xc07cc64  jal         func_1F3190
    ctx->pc = 0x1F35A4u;
    SET_GPR_U32(ctx, 31, 0x1F35ACu);
    ctx->pc = 0x1F3190u;
    if (runtime->hasFunction(0x1F3190u)) {
        auto targetFn = runtime->lookupFunction(0x1F3190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35ACu; }
        if (ctx->pc != 0x1F35ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3190_0x1f3190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35ACu; }
        if (ctx->pc != 0x1F35ACu) { return; }
    }
    ctx->pc = 0x1F35ACu;
label_1f35ac:
    // 0x1f35ac: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F35ACu;
    {
        const bool branch_taken_0x1f35ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f35ac) {
            ctx->pc = 0x1F35C0u;
            goto label_1f35c0;
        }
    }
    ctx->pc = 0x1F35B4u;
    // 0x1f35b4: 0x2402e0c2  addiu       $v0, $zero, -0x1F3E
    ctx->pc = 0x1f35b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959298));
    // 0x1f35b8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1F35B8u;
    {
        const bool branch_taken_0x1f35b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f35b8) {
            ctx->pc = 0x1F35F8u;
            goto label_1f35f8;
        }
    }
    ctx->pc = 0x1F35C0u;
label_1f35c0:
    // 0x1f35c0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f35c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f35c4: 0xc07cc13  jal         func_1F304C
    ctx->pc = 0x1F35C4u;
    SET_GPR_U32(ctx, 31, 0x1F35CCu);
    ctx->pc = 0x1F304Cu;
    if (runtime->hasFunction(0x1F304Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F304Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35CCu; }
        if (ctx->pc != 0x1F35CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F304C_0x1f304c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35CCu; }
        if (ctx->pc != 0x1F35CCu) { return; }
    }
    ctx->pc = 0x1F35CCu;
label_1f35cc:
    // 0x1f35cc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f35ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f35d0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f35d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f35d4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1f35d4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f35d8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F35D8u;
    SET_GPR_U32(ctx, 31, 0x1F35E0u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35E0u; }
        if (ctx->pc != 0x1F35E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35E0u; }
        if (ctx->pc != 0x1F35E0u) { return; }
    }
    ctx->pc = 0x1F35E0u;
label_1f35e0:
    // 0x1f35e0: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f35e0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f35e4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f35e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f35e8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f35e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f35ec: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1F35ECu;
    SET_GPR_U32(ctx, 31, 0x1F35F4u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35F4u; }
        if (ctx->pc != 0x1F35F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F35F4u; }
        if (ctx->pc != 0x1F35F4u) { return; }
    }
    ctx->pc = 0x1F35F4u;
label_1f35f4:
    // 0x1f35f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f35f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f35f8:
    // 0x1f35f8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f35f8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f35fc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f35fcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3600: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f3600u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3604: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3604u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f3608: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3608u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F35ACu: goto label_1f35ac;
            case 0x1F35C0u: goto label_1f35c0;
            case 0x1F35CCu: goto label_1f35cc;
            case 0x1F35E0u: goto label_1f35e0;
            case 0x1F35F4u: goto label_1f35f4;
            case 0x1F35F8u: goto label_1f35f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3610u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
