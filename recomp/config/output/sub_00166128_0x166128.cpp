#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166128
// Address: 0x166128 - 0x166350
void sub_00166128_0x166128(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166128_0x166128");
#endif

    switch (ctx->pc) {
        case 0x16617cu: goto label_16617c;
        case 0x1661b0u: goto label_1661b0;
        case 0x1661d0u: goto label_1661d0;
        case 0x166204u: goto label_166204;
        case 0x16621cu: goto label_16621c;
        case 0x166230u: goto label_166230;
        case 0x16624cu: goto label_16624c;
        case 0x16627cu: goto label_16627c;
        case 0x1662acu: goto label_1662ac;
        case 0x1662c8u: goto label_1662c8;
        case 0x1662f4u: goto label_1662f4;
        case 0x16630cu: goto label_16630c;
        case 0x166324u: goto label_166324;
        case 0x16633cu: goto label_16633c;
        default: break;
    }

    ctx->pc = 0x166128u;

    // 0x166128: 0x8c832ab0  lw          $v1, 0x2AB0($a0)
    ctx->pc = 0x166128u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10928)));
    // 0x16612c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16612cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166130: 0x8c841b74  lw          $a0, 0x1B74($a0)
    ctx->pc = 0x166130u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x166134: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x166134u;
    {
        const bool branch_taken_0x166134 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x166138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166134u;
            // 0x166138: 0x24650cfc  addiu       $a1, $v1, 0xCFC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 3324));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166134) {
            ctx->pc = 0x166150u;
            goto label_166150;
        }
    }
    ctx->pc = 0x16613Cu;
    // 0x16613c: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x16613cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x166140: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x166140u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166144: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x166144u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x166148: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166148u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16614c: 0xa3100a  movz        $v0, $a1, $v1
    ctx->pc = 0x16614cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
label_166150:
    // 0x166150: 0x3e00008  jr          $ra
    ctx->pc = 0x166150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166158u;
    // 0x166158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16615c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16615cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166160: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166160u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166164: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166168: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x166168u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16616c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16616cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x166170: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x166170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x166174: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x166174u;
    SET_GPR_U32(ctx, 31, 0x16617Cu);
    ctx->pc = 0x166178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166174u;
            // 0x166178: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16617Cu; }
        if (ctx->pc != 0x16617Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16617Cu; }
        if (ctx->pc != 0x16617Cu) { return; }
    }
    ctx->pc = 0x16617Cu;
label_16617c:
    // 0x16617c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16617cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166180: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166184: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x166184u;
    {
        const bool branch_taken_0x166184 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166184u;
            // 0x166188: 0x34a501a1  ori         $a1, $a1, 0x1A1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)417);
        ctx->in_delay_slot = false;
        if (branch_taken_0x166184) {
            ctx->pc = 0x1661A8u;
            goto label_1661a8;
        }
    }
    ctx->pc = 0x16618Cu;
    // 0x16618c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16618cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166190: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x166190u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166194: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166194u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166198: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x166198u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16619c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16619cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1661a0: 0x805a704  j           func_169C10
    ctx->pc = 0x1661A0u;
    ctx->pc = 0x1661A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1661A0u;
            // 0x1661a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1661A8u;
label_1661a8:
    // 0x1661a8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1661A8u;
    SET_GPR_U32(ctx, 31, 0x1661B0u);
    ctx->pc = 0x1661ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1661A8u;
            // 0x1661ac: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1661B0u; }
        if (ctx->pc != 0x1661B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1661B0u; }
        if (ctx->pc != 0x1661B0u) { return; }
    }
    ctx->pc = 0x1661B0u;
label_1661b0:
    // 0x1661b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1661b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1661b4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1661b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1661b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1661B8u;
    {
        const bool branch_taken_0x1661b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1661BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1661B8u;
            // 0x1661bc: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1661b8) {
            ctx->pc = 0x1661D0u;
            goto label_1661d0;
        }
    }
    ctx->pc = 0x1661C0u;
    // 0x1661c0: 0x8e021c84  lw          $v0, 0x1C84($s0)
    ctx->pc = 0x1661c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x1661c4: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1661c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1661c8: 0x60f809  jalr        $v1
    ctx->pc = 0x1661C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1661D0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1661D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1661D0u; }
            if (ctx->pc != 0x1661D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1661D0u;
label_1661d0:
    // 0x1661d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1661d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1661d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1661d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1661d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1661d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1661dc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1661dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1661e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1661E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1661E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1661E0u;
            // 0x1661e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1661E8u;
    // 0x1661e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1661e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1661ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1661ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1661f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1661f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1661f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1661f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1661f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1661f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1661fc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1661FCu;
    SET_GPR_U32(ctx, 31, 0x166204u);
    ctx->pc = 0x166200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1661FCu;
            // 0x166200: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166204u; }
        if (ctx->pc != 0x166204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166204u; }
        if (ctx->pc != 0x166204u) { return; }
    }
    ctx->pc = 0x166204u;
label_166204:
    // 0x166204: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x166204u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166208: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x166208u;
    {
        const bool branch_taken_0x166208 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16620Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166208u;
            // 0x16620c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166208) {
            ctx->pc = 0x166228u;
            goto label_166228;
        }
    }
    ctx->pc = 0x166210u;
    // 0x166210: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x166210u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166214: 0xc05a704  jal         func_169C10
    ctx->pc = 0x166214u;
    SET_GPR_U32(ctx, 31, 0x16621Cu);
    ctx->pc = 0x166218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166214u;
            // 0x166218: 0x34a501a2  ori         $a1, $a1, 0x1A2 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)418);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16621Cu; }
        if (ctx->pc != 0x16621Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16621Cu; }
        if (ctx->pc != 0x16621Cu) { return; }
    }
    ctx->pc = 0x16621Cu;
label_16621c:
    // 0x16621c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x16621Cu;
    {
        const bool branch_taken_0x16621c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x166220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16621Cu;
            // 0x166220: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16621c) {
            ctx->pc = 0x16624Cu;
            goto label_16624c;
        }
    }
    ctx->pc = 0x166224u;
    // 0x166224: 0x0  nop
    ctx->pc = 0x166224u;
    // NOP
label_166228:
    // 0x166228: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166228u;
    SET_GPR_U32(ctx, 31, 0x166230u);
    ctx->pc = 0x16622Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166228u;
            // 0x16622c: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166230u; }
        if (ctx->pc != 0x166230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166230u; }
        if (ctx->pc != 0x166230u) { return; }
    }
    ctx->pc = 0x166230u;
label_166230:
    // 0x166230: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166230u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166234: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x166234u;
    {
        const bool branch_taken_0x166234 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166234u;
            // 0x166238: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166234) {
            ctx->pc = 0x16624Cu;
            goto label_16624c;
        }
    }
    ctx->pc = 0x16623Cu;
    // 0x16623c: 0x8e031c84  lw          $v1, 0x1C84($s0)
    ctx->pc = 0x16623cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x166240: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x166240u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x166244: 0x40f809  jalr        $v0
    ctx->pc = 0x166244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16624Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x16624Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16624Cu; }
            if (ctx->pc != 0x16624Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16624Cu;
label_16624c:
    // 0x16624c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16624cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166250: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166250u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166254: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166258: 0x3e00008  jr          $ra
    ctx->pc = 0x166258u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16625Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166258u;
            // 0x16625c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166260u;
    // 0x166260: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166260u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166264: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166268: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166268u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16626c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16626cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166270: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x166270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166274: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x166274u;
    SET_GPR_U32(ctx, 31, 0x16627Cu);
    ctx->pc = 0x166278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166274u;
            // 0x166278: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16627Cu; }
        if (ctx->pc != 0x16627Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16627Cu; }
        if (ctx->pc != 0x16627Cu) { return; }
    }
    ctx->pc = 0x16627Cu;
label_16627c:
    // 0x16627c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16627cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166280: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x166280u;
    {
        const bool branch_taken_0x166280 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166280u;
            // 0x166284: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166280) {
            ctx->pc = 0x1662A0u;
            goto label_1662a0;
        }
    }
    ctx->pc = 0x166288u;
    // 0x166288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16628c: 0x34a501a3  ori         $a1, $a1, 0x1A3
    ctx->pc = 0x16628cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)419);
    // 0x166290: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166290u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166294: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166294u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166298: 0x805a704  j           func_169C10
    ctx->pc = 0x166298u;
    ctx->pc = 0x16629Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166298u;
            // 0x16629c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1662A0u;
label_1662a0:
    // 0x1662a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1662a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1662a4: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1662A4u;
    SET_GPR_U32(ctx, 31, 0x1662ACu);
    ctx->pc = 0x1662A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1662A4u;
            // 0x1662a8: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662ACu; }
        if (ctx->pc != 0x1662ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662ACu; }
        if (ctx->pc != 0x1662ACu) { return; }
    }
    ctx->pc = 0x1662ACu;
label_1662ac:
    // 0x1662ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1662acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1662b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1662B0u;
    {
        const bool branch_taken_0x1662b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1662B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1662B0u;
            // 0x1662b4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1662b0) {
            ctx->pc = 0x1662C8u;
            goto label_1662c8;
        }
    }
    ctx->pc = 0x1662B8u;
    // 0x1662b8: 0x8e021c84  lw          $v0, 0x1C84($s0)
    ctx->pc = 0x1662b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x1662bc: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1662bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1662c0: 0x60f809  jalr        $v1
    ctx->pc = 0x1662C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1662C8u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1662C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1662C8u; }
            if (ctx->pc != 0x1662C8u) { return; }
        }
        }
    }
    ctx->pc = 0x1662C8u;
label_1662c8:
    // 0x1662c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1662c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1662cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1662ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1662d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1662d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1662d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1662D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1662D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1662D4u;
            // 0x1662d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1662DCu;
    // 0x1662dc: 0x0  nop
    ctx->pc = 0x1662dcu;
    // NOP
    // 0x1662e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1662e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1662e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1662e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1662e8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1662e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1662ec: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1662ECu;
    SET_GPR_U32(ctx, 31, 0x1662F4u);
    ctx->pc = 0x1662F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1662ECu;
            // 0x1662f0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662F4u; }
        if (ctx->pc != 0x1662F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662F4u; }
        if (ctx->pc != 0x1662F4u) { return; }
    }
    ctx->pc = 0x1662F4u;
label_1662f4:
    // 0x1662f4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1662f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1662f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1662f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1662fc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1662FCu;
    {
        const bool branch_taken_0x1662fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1662FCu;
            // 0x166300: 0x34a501a4  ori         $a1, $a1, 0x1A4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)420);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1662fc) {
            ctx->pc = 0x166318u;
            goto label_166318;
        }
    }
    ctx->pc = 0x166304u;
    // 0x166304: 0xc05a704  jal         func_169C10
    ctx->pc = 0x166304u;
    SET_GPR_U32(ctx, 31, 0x16630Cu);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16630Cu; }
        if (ctx->pc != 0x16630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16630Cu; }
        if (ctx->pc != 0x16630Cu) { return; }
    }
    ctx->pc = 0x16630Cu;
label_16630c:
    // 0x16630c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x16630Cu;
    {
        const bool branch_taken_0x16630c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x166310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16630Cu;
            // 0x166310: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16630c) {
            ctx->pc = 0x16633Cu;
            goto label_16633c;
        }
    }
    ctx->pc = 0x166314u;
    // 0x166314: 0x0  nop
    ctx->pc = 0x166314u;
    // NOP
label_166318:
    // 0x166318: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16631c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16631Cu;
    SET_GPR_U32(ctx, 31, 0x166324u);
    ctx->pc = 0x166320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16631Cu;
            // 0x166320: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166324u; }
        if (ctx->pc != 0x166324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166324u; }
        if (ctx->pc != 0x166324u) { return; }
    }
    ctx->pc = 0x166324u;
label_166324:
    // 0x166324: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x166324u;
    {
        const bool branch_taken_0x166324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166324u;
            // 0x166328: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166324) {
            ctx->pc = 0x16633Cu;
            goto label_16633c;
        }
    }
    ctx->pc = 0x16632Cu;
    // 0x16632c: 0x8e031c84  lw          $v1, 0x1C84($s0)
    ctx->pc = 0x16632cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x166330: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x166330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x166334: 0x40f809  jalr        $v0
    ctx->pc = 0x166334u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16633Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x16633Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16633Cu; }
            if (ctx->pc != 0x16633Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16633Cu;
label_16633c:
    // 0x16633c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16633cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166340: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166340u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166344: 0x3e00008  jr          $ra
    ctx->pc = 0x166344u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166344u;
            // 0x166348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166150u: goto label_166150;
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            case 0x1662F4u: goto label_1662f4;
            case 0x16630Cu: goto label_16630c;
            case 0x166318u: goto label_166318;
            case 0x166324u: goto label_166324;
            case 0x16633Cu: goto label_16633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16634Cu;
    // 0x16634c: 0x0  nop
    ctx->pc = 0x16634cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
