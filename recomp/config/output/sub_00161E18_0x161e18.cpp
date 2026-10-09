#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161E18
// Address: 0x161e18 - 0x161e90
void sub_00161E18_0x161e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161E18_0x161e18");
#endif

    switch (ctx->pc) {
        case 0x161e48u: goto label_161e48;
        case 0x161e5cu: goto label_161e5c;
        case 0x161e70u: goto label_161e70;
        default: break;
    }

    ctx->pc = 0x161e18u;

    // 0x161e18: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161e1c: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x161e20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161e20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e24: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161e28: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x161e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161e2c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x161e2cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e30: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x161e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161e34: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x161e34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e38: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x161e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x161e3c: 0xffbf00b8  sd          $ra, 0xB8($sp)
    ctx->pc = 0x161e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 31));
    // 0x161e40: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161E40u;
    SET_GPR_U32(ctx, 31, 0x161E48u);
    ctx->pc = 0x161E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161E40u;
            // 0x161e44: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E48u; }
        if (ctx->pc != 0x161E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E48u; }
        if (ctx->pc != 0x161E48u) { return; }
    }
    ctx->pc = 0x161E48u;
label_161e48:
    // 0x161e48: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161e48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161e4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e50: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161e50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e54: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x161E54u;
    SET_GPR_U32(ctx, 31, 0x161E5Cu);
    ctx->pc = 0x161E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161E54u;
            // 0x161e58: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E5Cu; }
        if (ctx->pc != 0x161E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E5Cu; }
        if (ctx->pc != 0x161E5Cu) { return; }
    }
    ctx->pc = 0x161E5Cu;
label_161e5c:
    // 0x161e5c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161e5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e60: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x161e60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e64: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x161e64u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e68: 0xc05f504  jal         func_17D410
    ctx->pc = 0x161E68u;
    SET_GPR_U32(ctx, 31, 0x161E70u);
    ctx->pc = 0x161E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161E68u;
            // 0x161e6c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D410u;
    if (runtime->hasFunction(0x17D410u)) {
        auto targetFn = runtime->lookupFunction(0x17D410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E70u; }
        if (ctx->pc != 0x161E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D410_0x17d410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E70u; }
        if (ctx->pc != 0x161E70u) { return; }
    }
    ctx->pc = 0x161E70u;
label_161e70:
    // 0x161e70: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161e70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x161e74: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161e74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161e78: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161e78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161e7c: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161e7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161e80: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x161e80u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161e84: 0xdfbf00b8  ld          $ra, 0xB8($sp)
    ctx->pc = 0x161e84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x161e88: 0x3e00008  jr          $ra
    ctx->pc = 0x161E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161E88u;
            // 0x161e8c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161E90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
