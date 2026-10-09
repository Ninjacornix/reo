#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189880
// Address: 0x189880 - 0x189970
void sub_00189880_0x189880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189880_0x189880");
#endif

    switch (ctx->pc) {
        case 0x189920u: goto label_189920;
        case 0x189938u: goto label_189938;
        case 0x18994cu: goto label_18994c;
        default: break;
    }

    ctx->pc = 0x189880u;

    // 0x189880: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x189880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x189884: 0x2402c000  addiu       $v0, $zero, -0x4000
    ctx->pc = 0x189884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294950912));
    // 0x189888: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x189888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x18988c: 0x2403000b  addiu       $v1, $zero, 0xB
    ctx->pc = 0x18988cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x189890: 0x282a024  and         $s4, $s4, $v0
    ctx->pc = 0x189890u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x189894: 0x3c09ffff  lui         $t1, 0xFFFF
    ctx->pc = 0x189894u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)65535 << 16));
    // 0x189898: 0x35293fff  ori         $t1, $t1, 0x3FFF
    ctx->pc = 0x189898u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)16383);
    // 0x18989c: 0x283a025  or          $s4, $s4, $v1
    ctx->pc = 0x18989cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | GPR_U64(ctx, 3));
    // 0x1898a0: 0x24024000  addiu       $v0, $zero, 0x4000
    ctx->pc = 0x1898a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x1898a4: 0x289a024  and         $s4, $s4, $t1
    ctx->pc = 0x1898a4u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) & GPR_U64(ctx, 9));
    // 0x1898a8: 0x3c03ff00  lui         $v1, 0xFF00
    ctx->pc = 0x1898a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65280 << 16));
    // 0x1898ac: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x1898acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1898b0: 0x282a025  or          $s4, $s4, $v0
    ctx->pc = 0x1898b0u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x1898b4: 0x3c090003  lui         $t1, 0x3
    ctx->pc = 0x1898b4u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)3 << 16));
    // 0x1898b8: 0x283a024  and         $s4, $s4, $v1
    ctx->pc = 0x1898b8u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) & GPR_U64(ctx, 3));
    // 0x1898bc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1898bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1898c0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1898c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1898c4: 0x344200ff  ori         $v0, $v0, 0xFF
    ctx->pc = 0x1898c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)255);
    // 0x1898c8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1898c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1898cc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1898ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1898d0: 0x289a025  or          $s4, $s4, $t1
    ctx->pc = 0x1898d0u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | GPR_U64(ctx, 9));
    // 0x1898d4: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x1898d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x1898d8: 0x282a024  and         $s4, $s4, $v0
    ctx->pc = 0x1898d8u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x1898dc: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x1898dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x1898e0: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x1898e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x1898e4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1898e4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1898e8: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x1898e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x1898ec: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1898ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1898f0: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x1898f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1898f4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1898f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1898f8: 0x24030028  addiu       $v1, $zero, 0x28
    ctx->pc = 0x1898f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1898fc: 0x3c020100  lui         $v0, 0x100
    ctx->pc = 0x1898fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)256 << 16));
    // 0x189900: 0x282a025  or          $s4, $s4, $v0
    ctx->pc = 0x189900u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x189904: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x189904u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x189908: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x189908u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18990c: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x18990cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x189910: 0xafa30030  sw          $v1, 0x30($sp)
    ctx->pc = 0x189910u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
    // 0x189914: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x189914u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189918: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x189918u;
    SET_GPR_U32(ctx, 31, 0x189920u);
    ctx->pc = 0x18991Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189918u;
            // 0x18991c: 0x37a40008  ori         $a0, $sp, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189920u; }
        if (ctx->pc != 0x189920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189920u; }
        if (ctx->pc != 0x189920u) { return; }
    }
    ctx->pc = 0x189920u;
label_189920:
    // 0x189920: 0x21d8021  addu        $s0, $s0, $sp
    ctx->pc = 0x189920u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 29)));
    // 0x189924: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x189924u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189928: 0x26040008  addiu       $a0, $s0, 0x8
    ctx->pc = 0x189928u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x18992c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18992cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189930: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x189930u;
    SET_GPR_U32(ctx, 31, 0x189938u);
    ctx->pc = 0x189934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189930u;
            // 0x189934: 0xafb10000  sw          $s1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189938u; }
        if (ctx->pc != 0x189938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189938u; }
        if (ctx->pc != 0x189938u) { return; }
    }
    ctx->pc = 0x189938u;
label_189938:
    // 0x189938: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x189938u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18993c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x18993cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189940: 0x27a60030  addiu       $a2, $sp, 0x30
    ctx->pc = 0x189940u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x189944: 0xc062508  jal         func_189420
    ctx->pc = 0x189944u;
    SET_GPR_U32(ctx, 31, 0x18994Cu);
    ctx->pc = 0x189948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189944u;
            // 0x189948: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189420u;
    if (runtime->hasFunction(0x189420u)) {
        auto targetFn = runtime->lookupFunction(0x189420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18994Cu; }
        if (ctx->pc != 0x18994Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189420_0x189420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18994Cu; }
        if (ctx->pc != 0x18994Cu) { return; }
    }
    ctx->pc = 0x18994Cu;
label_18994c:
    // 0x18994c: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x18994cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x189950: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x189950u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x189954: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x189954u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x189958: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x189958u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18995c: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x18995cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x189960: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x189960u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x189964: 0x3e00008  jr          $ra
    ctx->pc = 0x189964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189964u;
            // 0x189968: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189920u: goto label_189920;
            case 0x189938u: goto label_189938;
            case 0x18994Cu: goto label_18994c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18996Cu;
    // 0x18996c: 0x0  nop
    ctx->pc = 0x18996cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
