#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001661E8
// Address: 0x1661e8 - 0x166260
void sub_001661E8_0x1661e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001661E8_0x1661e8");
#endif

    switch (ctx->pc) {
        case 0x166204u: goto label_166204;
        case 0x16621cu: goto label_16621c;
        case 0x166230u: goto label_166230;
        case 0x16624cu: goto label_16624c;
        default: break;
    }

    ctx->pc = 0x1661e8u;

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
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
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
            case 0x166204u: goto label_166204;
            case 0x16621Cu: goto label_16621c;
            case 0x166228u: goto label_166228;
            case 0x166230u: goto label_166230;
            case 0x16624Cu: goto label_16624c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166260u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
