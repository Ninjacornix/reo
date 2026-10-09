#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A95A0
// Address: 0x1a95a0 - 0x1a9750
void sub_001A95A0_0x1a95a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A95A0_0x1a95a0");
#endif

    switch (ctx->pc) {
        case 0x1a96bcu: goto label_1a96bc;
        case 0x1a96c8u: goto label_1a96c8;
        case 0x1a96fcu: goto label_1a96fc;
        case 0x1a9704u: goto label_1a9704;
        case 0x1a9718u: goto label_1a9718;
        case 0x1a9724u: goto label_1a9724;
        default: break;
    }

    ctx->pc = 0x1a95a0u;

    // 0x1a95a0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1a95a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1a95a4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1a95a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1a95a8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a95a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a95ac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a95acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a95b0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a95b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a95b4: 0x2e21000a  sltiu       $at, $s1, 0xA
    ctx->pc = 0x1a95b4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1a95b8: 0x10200036  beqz        $at, . + 4 + (0x36 << 2)
    ctx->pc = 0x1A95B8u;
    {
        const bool branch_taken_0x1a95b8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A95BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A95B8u;
            // 0x1a95bc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a95b8) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A95C0u;
    // 0x1a95c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a95c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a95c4: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1a95c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1a95c8: 0x24842650  addiu       $a0, $a0, 0x2650
    ctx->pc = 0x1a95c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9808));
    // 0x1a95cc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a95ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a95d0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a95d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a95d4: 0x600008  jr          $v1
    ctx->pc = 0x1A95D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A95DCu: goto label_1a95dc;
            case 0x1A95FCu: goto label_1a95fc;
            case 0x1A962Cu: goto label_1a962c;
            case 0x1A9664u: goto label_1a9664;
            case 0x1A9680u: goto label_1a9680;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A95DCu;
label_1a95dc:
    // 0x1a95dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a95dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a95e0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a95e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a95e4: 0xa0222210  sb          $v0, 0x2210($at)
    ctx->pc = 0x1a95e4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 8720), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a95e8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a95e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a95ec: 0xa0222218  sb          $v0, 0x2218($at)
    ctx->pc = 0x1a95ecu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 8728), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a95f0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a95f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a95f4: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1A95F4u;
    {
        const bool branch_taken_0x1a95f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A95F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A95F4u;
            // 0x1a95f8: 0xa0222220  sb          $v0, 0x2220($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 8736), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a95f4) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A95FCu;
label_1a95fc:
    // 0x1a95fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a95fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a9600: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1a9600u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1a9604: 0x80232210  lb          $v1, 0x2210($at)
    ctx->pc = 0x1a9604u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8720)));
    // 0x1a9608: 0x1223004b  beq         $s1, $v1, . + 4 + (0x4B << 2)
    ctx->pc = 0x1A9608u;
    {
        const bool branch_taken_0x1a9608 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A960Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9608u;
            // 0x1a960c: 0x26102210  addiu       $s0, $s0, 0x2210 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8720));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9608) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9610u;
    // 0x1a9610: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1a9610u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a9614: 0x1622001f  bne         $s1, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1A9614u;
    {
        const bool branch_taken_0x1a9614 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x1a9614) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A961Cu;
    // 0x1a961c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a961cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a9620: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a9620u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a9624: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1A9624u;
    {
        const bool branch_taken_0x1a9624 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9624u;
            // 0x1a9628: 0xa0222220  sb          $v0, 0x2220($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 8736), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9624) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A962Cu;
label_1a962c:
    // 0x1a962c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a962cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a9630: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a9630u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a9634: 0x80242210  lb          $a0, 0x2210($at)
    ctx->pc = 0x1a9634u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8720)));
    // 0x1a9638: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A9638u;
    {
        const bool branch_taken_0x1a9638 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a9638) {
            ctx->pc = 0x1A9658u;
            goto label_1a9658;
        }
    }
    ctx->pc = 0x1A9640u;
    // 0x1a9640: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a9640u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9644: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A9644u;
    {
        const bool branch_taken_0x1a9644 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a9644) {
            ctx->pc = 0x1A9658u;
            goto label_1a9658;
        }
    }
    ctx->pc = 0x1A964Cu;
    // 0x1a964c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1a964cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a9650: 0x14830039  bne         $a0, $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x1A9650u;
    {
        const bool branch_taken_0x1a9650 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a9650) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9658u;
label_1a9658:
    // 0x1a9658: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1a9658u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1a965c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1A965Cu;
    {
        const bool branch_taken_0x1a965c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A965Cu;
            // 0x1a9660: 0x26102220  addiu       $s0, $s0, 0x2220 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8736));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a965c) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A9664u;
label_1a9664:
    // 0x1a9664: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a9664u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a9668: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a9668u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a966c: 0x80242210  lb          $a0, 0x2210($at)
    ctx->pc = 0x1a966cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8720)));
    // 0x1a9670: 0x14830031  bne         $a0, $v1, . + 4 + (0x31 << 2)
    ctx->pc = 0x1A9670u;
    {
        const bool branch_taken_0x1a9670 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1A9674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9670u;
            // 0x1a9674: 0x3c100023  lui         $s0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9670) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9678u;
    // 0x1a9678: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A9678u;
    {
        const bool branch_taken_0x1a9678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A967Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9678u;
            // 0x1a967c: 0x26102220  addiu       $s0, $s0, 0x2220 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8736));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9678) {
            ctx->pc = 0x1A9694u;
            goto label_1a9694;
        }
    }
    ctx->pc = 0x1A9680u;
label_1a9680:
    // 0x1a9680: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a9680u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a9684: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1a9684u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1a9688: 0x80232218  lb          $v1, 0x2218($at)
    ctx->pc = 0x1a9688u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 8728)));
    // 0x1a968c: 0x1223002a  beq         $s1, $v1, . + 4 + (0x2A << 2)
    ctx->pc = 0x1A968Cu;
    {
        const bool branch_taken_0x1a968c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A9690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A968Cu;
            // 0x1a9690: 0x26102218  addiu       $s0, $s0, 0x2218 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8728));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a968c) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9694u;
label_1a9694:
    // 0x1a9694: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1a9694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1a9698: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a9698u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a969c: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1a969cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1a96a0: 0x244211a0  addiu       $v0, $v0, 0x11A0
    ctx->pc = 0x1a96a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4512));
    // 0x1a96a4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a96a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a96a8: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1a96a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1a96ac: 0x8c520000  lw          $s2, 0x0($v0)
    ctx->pc = 0x1a96acu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a96b0: 0x24a52638  addiu       $a1, $a1, 0x2638
    ctx->pc = 0x1a96b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9784));
    // 0x1a96b4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1A96B4u;
    SET_GPR_U32(ctx, 31, 0x1A96BCu);
    ctx->pc = 0x1A96B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96B4u;
            // 0x1a96b8: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96BCu; }
        if (ctx->pc != 0x1A96BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96BCu; }
        if (ctx->pc != 0x1A96BCu) { return; }
    }
    ctx->pc = 0x1A96BCu;
label_1a96bc:
    // 0x1a96bc: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1a96bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1a96c0: 0xc06a540  jal         func_1A9500
    ctx->pc = 0x1A96C0u;
    SET_GPR_U32(ctx, 31, 0x1A96C8u);
    ctx->pc = 0x1A96C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96C0u;
            // 0x1a96c4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9500u;
    if (runtime->hasFunction(0x1A9500u)) {
        auto targetFn = runtime->lookupFunction(0x1A9500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96C8u; }
        if (ctx->pc != 0x1A96C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9500_0x1a9500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96C8u; }
        if (ctx->pc != 0x1A96C8u) { return; }
    }
    ctx->pc = 0x1A96C8u;
label_1a96c8:
    // 0x1a96c8: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1A96C8u;
    {
        const bool branch_taken_0x1a96c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a96c8) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A96D0u;
    // 0x1a96d0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1a96d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a96d4: 0x1222000e  beq         $s1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1A96D4u;
    {
        const bool branch_taken_0x1a96d4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A96D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96D4u;
            // 0x1a96d8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a96d4) {
            ctx->pc = 0x1A9710u;
            goto label_1a9710;
        }
    }
    ctx->pc = 0x1A96DCu;
    // 0x1a96dc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1a96dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a96e0: 0x1222000a  beq         $s1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1A96E0u;
    {
        const bool branch_taken_0x1a96e0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A96E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96E0u;
            // 0x1a96e4: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a96e0) {
            ctx->pc = 0x1A970Cu;
            goto label_1a970c;
        }
    }
    ctx->pc = 0x1A96E8u;
    // 0x1a96e8: 0x12220008  beq         $s1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A96E8u;
    {
        const bool branch_taken_0x1a96e8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A96ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96E8u;
            // 0x1a96ec: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a96e8) {
            ctx->pc = 0x1A970Cu;
            goto label_1a970c;
        }
    }
    ctx->pc = 0x1A96F0u;
    // 0x1a96f0: 0x8c25440c  lw          $a1, 0x440C($at)
    ctx->pc = 0x1a96f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1a96f4: 0xc06bd74  jal         func_1AF5D0
    ctx->pc = 0x1A96F4u;
    SET_GPR_U32(ctx, 31, 0x1A96FCu);
    ctx->pc = 0x1A96F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96F4u;
            // 0x1a96f8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5D0u;
    if (runtime->hasFunction(0x1AF5D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96FCu; }
        if (ctx->pc != 0x1A96FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5D0_0x1af5d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A96FCu; }
        if (ctx->pc != 0x1A96FCu) { return; }
    }
    ctx->pc = 0x1A96FCu;
label_1a96fc:
    // 0x1a96fc: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1A96FCu;
    SET_GPR_U32(ctx, 31, 0x1A9704u);
    ctx->pc = 0x1A9700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A96FCu;
            // 0x1a9700: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9704u; }
        if (ctx->pc != 0x1A9704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9704u; }
        if (ctx->pc != 0x1A9704u) { return; }
    }
    ctx->pc = 0x1A9704u;
label_1a9704:
    // 0x1a9704: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1a9704u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1a9708: 0x8c32440c  lw          $s2, 0x440C($at)
    ctx->pc = 0x1a9708u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
label_1a970c:
    // 0x1a970c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a970cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1a9710:
    // 0x1a9710: 0xc06a520  jal         func_1A9480
    ctx->pc = 0x1A9710u;
    SET_GPR_U32(ctx, 31, 0x1A9718u);
    ctx->pc = 0x1A9480u;
    if (runtime->hasFunction(0x1A9480u)) {
        auto targetFn = runtime->lookupFunction(0x1A9480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9718u; }
        if (ctx->pc != 0x1A9718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9480_0x1a9480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9718u; }
        if (ctx->pc != 0x1A9718u) { return; }
    }
    ctx->pc = 0x1A9718u;
label_1a9718:
    // 0x1a9718: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1a9718u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a971c: 0xc07dc7c  jal         func_1F71F0
    ctx->pc = 0x1A971Cu;
    SET_GPR_U32(ctx, 31, 0x1A9724u);
    ctx->pc = 0x1A9720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A971Cu;
            // 0x1a9720: 0x26240001  addiu       $a0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F71F0u;
    if (runtime->hasFunction(0x1F71F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F71F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9724u; }
        if (ctx->pc != 0x1A9724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F71F0_0x1f71f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9724u; }
        if (ctx->pc != 0x1A9724u) { return; }
    }
    ctx->pc = 0x1A9724u;
label_1a9724:
    // 0x1a9724: 0x12200004  beqz        $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A9724u;
    {
        const bool branch_taken_0x1a9724 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9724u;
            // 0x1a9728: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9724) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A972Cu;
    // 0x1a972c: 0x16430002  bne         $s2, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A972Cu;
    {
        const bool branch_taken_0x1a972c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a972c) {
            ctx->pc = 0x1A9738u;
            goto label_1a9738;
        }
    }
    ctx->pc = 0x1A9734u;
    // 0x1a9734: 0xa2110000  sb          $s1, 0x0($s0)
    ctx->pc = 0x1a9734u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 17));
label_1a9738:
    // 0x1a9738: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1a9738u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a973c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a973cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a9740: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a9740u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a9744: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a9744u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9748: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A974Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9748u;
            // 0x1a974c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A95DCu: goto label_1a95dc;
            case 0x1A95FCu: goto label_1a95fc;
            case 0x1A962Cu: goto label_1a962c;
            case 0x1A9658u: goto label_1a9658;
            case 0x1A9664u: goto label_1a9664;
            case 0x1A9680u: goto label_1a9680;
            case 0x1A9694u: goto label_1a9694;
            case 0x1A96BCu: goto label_1a96bc;
            case 0x1A96C8u: goto label_1a96c8;
            case 0x1A96FCu: goto label_1a96fc;
            case 0x1A9704u: goto label_1a9704;
            case 0x1A970Cu: goto label_1a970c;
            case 0x1A9710u: goto label_1a9710;
            case 0x1A9718u: goto label_1a9718;
            case 0x1A9724u: goto label_1a9724;
            case 0x1A9738u: goto label_1a9738;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9750u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
