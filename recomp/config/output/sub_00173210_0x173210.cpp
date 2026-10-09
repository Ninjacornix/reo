#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173210
// Address: 0x173210 - 0x1732d8
void sub_00173210_0x173210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173210_0x173210");
#endif

    switch (ctx->pc) {
        case 0x173250u: goto label_173250;
        case 0x173260u: goto label_173260;
        case 0x173270u: goto label_173270;
        default: break;
    }

    ctx->pc = 0x173210u;

    // 0x173210: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173214: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173218: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x173218u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17321c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17321cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x173220: 0x260309a0  addiu       $v1, $s0, 0x9A0
    ctx->pc = 0x173220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2464));
    // 0x173224: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x173224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x173228: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x173228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17322c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x17322cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x173230: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x173230u;
    {
        const bool branch_taken_0x173230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173230u;
            // 0x173234: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173230) {
            ctx->pc = 0x173248u;
            goto label_173248;
        }
    }
    ctx->pc = 0x173238u;
    // 0x173238: 0x8c630014  lw          $v1, 0x14($v1)
    ctx->pc = 0x173238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x17323c: 0x10600020  beqz        $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x17323Cu;
    {
        const bool branch_taken_0x17323c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x173240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17323Cu;
            // 0x173240: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17323c) {
            ctx->pc = 0x1732C0u;
            goto label_1732c0;
        }
    }
    ctx->pc = 0x173244u;
    // 0x173244: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x173244u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_173248:
    // 0x173248: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x173248u;
    SET_GPR_U32(ctx, 31, 0x173250u);
    ctx->pc = 0x17324Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173248u;
            // 0x17324c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173250u; }
        if (ctx->pc != 0x173250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173250u; }
        if (ctx->pc != 0x173250u) { return; }
    }
    ctx->pc = 0x173250u;
label_173250:
    // 0x173250: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173250u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173254: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x173254u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173258: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x173258u;
    SET_GPR_U32(ctx, 31, 0x173260u);
    ctx->pc = 0x17325Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173258u;
            // 0x17325c: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173260u; }
        if (ctx->pc != 0x173260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173260u; }
        if (ctx->pc != 0x173260u) { return; }
    }
    ctx->pc = 0x173260u;
label_173260:
    // 0x173260: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173264: 0x24050019  addiu       $a1, $zero, 0x19
    ctx->pc = 0x173264u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x173268: 0xc05d58a  jal         func_175628
    ctx->pc = 0x173268u;
    SET_GPR_U32(ctx, 31, 0x173270u);
    ctx->pc = 0x17326Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173268u;
            // 0x17326c: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173270u; }
        if (ctx->pc != 0x173270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173270u; }
        if (ctx->pc != 0x173270u) { return; }
    }
    ctx->pc = 0x173270u;
label_173270:
    // 0x173270: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x173270u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173274: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x173274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173278: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x173278u;
    {
        const bool branch_taken_0x173278 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17327Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173278u;
            // 0x17327c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173278) {
            ctx->pc = 0x1732A8u;
            goto label_1732a8;
        }
    }
    ctx->pc = 0x173280u;
    // 0x173280: 0x5060000e  beql        $v1, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x173280u;
    {
        const bool branch_taken_0x173280 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x173280) {
            ctx->pc = 0x173284u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173280u;
            // 0x173284: 0x2322024  and         $a0, $s1, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1732BCu;
            goto label_1732bc;
        }
    }
    ctx->pc = 0x173288u;
    // 0x173288: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x173288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17328c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17328Cu;
    {
        const bool branch_taken_0x17328c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x173290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17328Cu;
            // 0x173290: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17328c) {
            ctx->pc = 0x1732B0u;
            goto label_1732b0;
        }
    }
    ctx->pc = 0x173294u;
    // 0x173294: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x173294u;
    {
        const bool branch_taken_0x173294 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x173298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173294u;
            // 0x173298: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173294) {
            ctx->pc = 0x1732B8u;
            goto label_1732b8;
        }
    }
    ctx->pc = 0x17329Cu;
    // 0x17329c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x17329Cu;
    {
        const bool branch_taken_0x17329c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1732A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17329Cu;
            // 0x1732a0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17329c) {
            ctx->pc = 0x1732C4u;
            goto label_1732c4;
        }
    }
    ctx->pc = 0x1732A4u;
    // 0x1732a4: 0x0  nop
    ctx->pc = 0x1732a4u;
    // NOP
label_1732a8:
    // 0x1732a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1732A8u;
    {
        const bool branch_taken_0x1732a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1732ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1732A8u;
            // 0x1732ac: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1732a8) {
            ctx->pc = 0x1732BCu;
            goto label_1732bc;
        }
    }
    ctx->pc = 0x1732B0u;
label_1732b0:
    // 0x1732b0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1732B0u;
    {
        const bool branch_taken_0x1732b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1732B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1732B0u;
            // 0x1732b4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1732b0) {
            ctx->pc = 0x1732BCu;
            goto label_1732bc;
        }
    }
    ctx->pc = 0x1732B8u;
label_1732b8:
    // 0x1732b8: 0x2322025  or          $a0, $s1, $s2
    ctx->pc = 0x1732b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | GPR_U64(ctx, 18));
label_1732bc:
    // 0x1732bc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1732bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1732c0:
    // 0x1732c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1732c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1732c4:
    // 0x1732c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1732c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1732c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1732c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1732cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1732ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1732d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1732D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1732D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1732D0u;
            // 0x1732d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173248u: goto label_173248;
            case 0x173250u: goto label_173250;
            case 0x173260u: goto label_173260;
            case 0x173270u: goto label_173270;
            case 0x1732A8u: goto label_1732a8;
            case 0x1732B0u: goto label_1732b0;
            case 0x1732B8u: goto label_1732b8;
            case 0x1732BCu: goto label_1732bc;
            case 0x1732C0u: goto label_1732c0;
            case 0x1732C4u: goto label_1732c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1732D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
