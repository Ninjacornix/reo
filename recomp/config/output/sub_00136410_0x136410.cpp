#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136410
// Address: 0x136410 - 0x1364cc
void sub_00136410_0x136410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136410_0x136410");
#endif

    switch (ctx->pc) {
        case 0x13644cu: goto label_13644c;
        case 0x136474u: goto label_136474;
        case 0x13648cu: goto label_13648c;
        case 0x1364a0u: goto label_1364a0;
        case 0x1364b4u: goto label_1364b4;
        default: break;
    }

    ctx->pc = 0x136410u;

    // 0x136410: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x136414: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x136414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136418: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136418u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13641c: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x13641cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136420: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136420u;
    {
        const bool branch_taken_0x136420 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x136424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136420u;
            // 0x136424: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136420) {
            ctx->pc = 0x136438u;
            goto label_136438;
        }
    }
    ctx->pc = 0x136428u;
    // 0x136428: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136428u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13642c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x13642Cu;
    {
        const bool branch_taken_0x13642c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13642Cu;
            // 0x136430: 0x2484bd60  addiu       $a0, $a0, -0x42A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13642c) {
            ctx->pc = 0x1364ACu;
            goto label_1364ac;
        }
    }
    ctx->pc = 0x136434u;
    // 0x136434: 0x0  nop
    ctx->pc = 0x136434u;
    // NOP
label_136438:
    // 0x136438: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x136438u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13643c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13643cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136440: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x136440u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136444: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x136444u;
    SET_GPR_U32(ctx, 31, 0x13644Cu);
    ctx->pc = 0x136448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136444u;
            // 0x136448: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13644Cu; }
        if (ctx->pc != 0x13644Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13644Cu; }
        if (ctx->pc != 0x13644Cu) { return; }
    }
    ctx->pc = 0x13644Cu;
label_13644c:
    // 0x13644c: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x13644cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x136450: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136450u;
    {
        const bool branch_taken_0x136450 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x136454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136450u;
            // 0x136454: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136450) {
            ctx->pc = 0x136468u;
            goto label_136468;
        }
    }
    ctx->pc = 0x136458u;
    // 0x136458: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136458u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13645c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x13645Cu;
    {
        const bool branch_taken_0x13645c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13645Cu;
            // 0x136460: 0x2484bd60  addiu       $a0, $a0, -0x42A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13645c) {
            ctx->pc = 0x1364ACu;
            goto label_1364ac;
        }
    }
    ctx->pc = 0x136464u;
    // 0x136464: 0x0  nop
    ctx->pc = 0x136464u;
    // NOP
label_136468:
    // 0x136468: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13646c: 0xc04d622  jal         func_135888
    ctx->pc = 0x13646Cu;
    SET_GPR_U32(ctx, 31, 0x136474u);
    ctx->pc = 0x136470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13646Cu;
            // 0x136470: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136474u; }
        if (ctx->pc != 0x136474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136474u; }
        if (ctx->pc != 0x136474u) { return; }
    }
    ctx->pc = 0x136474u;
label_136474:
    // 0x136474: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x136474u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136478: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136478u;
    {
        const bool branch_taken_0x136478 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136478) {
            ctx->pc = 0x13647Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136478u;
            // 0x13647c: 0x8e02003c  lw          $v0, 0x3C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136490u;
            goto label_136490;
        }
    }
    ctx->pc = 0x136480u;
    // 0x136480: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136480u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136484: 0xc04d480  jal         func_135200
    ctx->pc = 0x136484u;
    SET_GPR_U32(ctx, 31, 0x13648Cu);
    ctx->pc = 0x136488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136484u;
            // 0x136488: 0x2484bdb0  addiu       $a0, $a0, -0x4250 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13648Cu; }
        if (ctx->pc != 0x13648Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13648Cu; }
        if (ctx->pc != 0x13648Cu) { return; }
    }
    ctx->pc = 0x13648Cu;
label_13648c:
    // 0x13648c: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x13648cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
label_136490:
    // 0x136490: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136490u;
    {
        const bool branch_taken_0x136490 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136490) {
            ctx->pc = 0x136494u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136490u;
            // 0x136494: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1364A8u;
            goto label_1364a8;
        }
    }
    ctx->pc = 0x136498u;
    // 0x136498: 0x40f809  jalr        $v0
    ctx->pc = 0x136498u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1364A0u);
        ctx->pc = 0x13649Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136498u;
            // 0x13649c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1364A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1364A0u; }
            if (ctx->pc != 0x1364A0u) { return; }
        }
        }
    }
    ctx->pc = 0x1364A0u;
label_1364a0:
    // 0x1364a0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1364A0u;
    {
        const bool branch_taken_0x1364a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1364A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1364A0u;
            // 0x1364a4: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1364a0) {
            ctx->pc = 0x1364BCu;
            goto label_1364bc;
        }
    }
    ctx->pc = 0x1364A8u;
label_1364a8:
    // 0x1364a8: 0x2484bdd8  addiu       $a0, $a0, -0x4228
    ctx->pc = 0x1364a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950360));
label_1364ac:
    // 0x1364ac: 0xc04d480  jal         func_135200
    ctx->pc = 0x1364ACu;
    SET_GPR_U32(ctx, 31, 0x1364B4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364B4u; }
        if (ctx->pc != 0x1364B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364B4u; }
        if (ctx->pc != 0x1364B4u) { return; }
    }
    ctx->pc = 0x1364B4u;
label_1364b4:
    // 0x1364b4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1364b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1364b8: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x1364b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_1364bc:
    // 0x1364bc: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x1364bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x1364c0: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x1364c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x1364c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1364C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1364C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1364C4u;
            // 0x1364c8: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1364CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
