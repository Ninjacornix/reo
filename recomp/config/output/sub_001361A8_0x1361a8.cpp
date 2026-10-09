#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001361A8
// Address: 0x1361a8 - 0x1362e8
void sub_001361A8_0x1361a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001361A8_0x1361a8");
#endif

    switch (ctx->pc) {
        case 0x1361ecu: goto label_1361ec;
        case 0x136210u: goto label_136210;
        case 0x136220u: goto label_136220;
        case 0x136228u: goto label_136228;
        case 0x136258u: goto label_136258;
        case 0x136270u: goto label_136270;
        case 0x136298u: goto label_136298;
        case 0x1362a8u: goto label_1362a8;
        default: break;
    }

    ctx->pc = 0x1361a8u;

    // 0x1361a8: 0x27bdfe90  addiu       $sp, $sp, -0x170
    ctx->pc = 0x1361a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966928));
    // 0x1361ac: 0xffb00130  sd          $s0, 0x130($sp)
    ctx->pc = 0x1361acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 16));
    // 0x1361b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1361b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1361b4: 0xffb40150  sd          $s4, 0x150($sp)
    ctx->pc = 0x1361b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 336), GPR_U64(ctx, 20));
    // 0x1361b8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1361b8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1361bc: 0xffb10138  sd          $s1, 0x138($sp)
    ctx->pc = 0x1361bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 312), GPR_U64(ctx, 17));
    // 0x1361c0: 0xffb20140  sd          $s2, 0x140($sp)
    ctx->pc = 0x1361c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 320), GPR_U64(ctx, 18));
    // 0x1361c4: 0xffb30148  sd          $s3, 0x148($sp)
    ctx->pc = 0x1361c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 328), GPR_U64(ctx, 19));
    // 0x1361c8: 0xffb50158  sd          $s5, 0x158($sp)
    ctx->pc = 0x1361c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 344), GPR_U64(ctx, 21));
    // 0x1361cc: 0xffb60160  sd          $s6, 0x160($sp)
    ctx->pc = 0x1361ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 352), GPR_U64(ctx, 22));
    // 0x1361d0: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1361D0u;
    {
        const bool branch_taken_0x1361d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1361D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1361D0u;
            // 0x1361d4: 0xffbf0168  sd          $ra, 0x168($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 360), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1361d0) {
            ctx->pc = 0x1361E4u;
            goto label_1361e4;
        }
    }
    ctx->pc = 0x1361D8u;
    // 0x1361d8: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1361d8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1361dc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1361DCu;
    {
        const bool branch_taken_0x1361dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1361dc) {
            ctx->pc = 0x136208u;
            goto label_136208;
        }
    }
    ctx->pc = 0x1361E4u;
label_1361e4:
    // 0x1361e4: 0xc04d706  jal         func_135C18
    ctx->pc = 0x1361E4u;
    SET_GPR_U32(ctx, 31, 0x1361ECu);
    ctx->pc = 0x1361E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1361E4u;
            // 0x1361e8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135C18u;
    if (runtime->hasFunction(0x135C18u)) {
        auto targetFn = runtime->lookupFunction(0x135C18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1361ECu; }
        if (ctx->pc != 0x1361ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135C18_0x135c18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1361ECu; }
        if (ctx->pc != 0x1361ECu) { return; }
    }
    ctx->pc = 0x1361ECu;
label_1361ec:
    // 0x1361ec: 0x83a20000  lb          $v0, 0x0($sp)
    ctx->pc = 0x1361ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1361f0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1361F0u;
    {
        const bool branch_taken_0x1361f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1361f0) {
            ctx->pc = 0x136220u;
            goto label_136220;
        }
    }
    ctx->pc = 0x1361F8u;
    // 0x1361f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1361f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1361fc: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1361FCu;
    {
        const bool branch_taken_0x1361fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1361FCu;
            // 0x136200: 0x2484bc58  addiu       $a0, $a0, -0x43A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1361fc) {
            ctx->pc = 0x1362A0u;
            goto label_1362a0;
        }
    }
    ctx->pc = 0x136204u;
    // 0x136204: 0x0  nop
    ctx->pc = 0x136204u;
    // NOP
label_136208:
    // 0x136208: 0xc042c56  jal         func_10B158
    ctx->pc = 0x136208u;
    SET_GPR_U32(ctx, 31, 0x136210u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136210u; }
        if (ctx->pc != 0x136210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136210u; }
        if (ctx->pc != 0x136210u) { return; }
    }
    ctx->pc = 0x136210u;
label_136210:
    // 0x136210: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x136210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136214: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136214u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136218: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x136218u;
    SET_GPR_U32(ctx, 31, 0x136220u);
    ctx->pc = 0x13621Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136218u;
            // 0x13621c: 0x24460001  addiu       $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136220u; }
        if (ctx->pc != 0x136220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136220u; }
        if (ctx->pc != 0x136220u) { return; }
    }
    ctx->pc = 0x136220u;
label_136220:
    // 0x136220: 0xc042c56  jal         func_10B158
    ctx->pc = 0x136220u;
    SET_GPR_U32(ctx, 31, 0x136228u);
    ctx->pc = 0x136224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136220u;
            // 0x136224: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136228u; }
        if (ctx->pc != 0x136228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136228u; }
        if (ctx->pc != 0x136228u) { return; }
    }
    ctx->pc = 0x136228u;
label_136228:
    // 0x136228: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x136228u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13622c: 0x5e400004  bgtzl       $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13622Cu;
    {
        const bool branch_taken_0x13622c = (GPR_S64(ctx, 18) > 0);
        if (branch_taken_0x13622c) {
            ctx->pc = 0x136230u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13622Cu;
            // 0x136230: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136240u;
            goto label_136240;
        }
    }
    ctx->pc = 0x136234u;
    // 0x136234: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136234u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136238: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x136238u;
    {
        const bool branch_taken_0x136238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13623Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136238u;
            // 0x13623c: 0x2484bc58  addiu       $a0, $a0, -0x43A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136238) {
            ctx->pc = 0x1362A0u;
            goto label_1362a0;
        }
    }
    ctx->pc = 0x136240u;
label_136240:
    // 0x136240: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x136240u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136244: 0x2453206c  addiu       $s3, $v0, 0x206C
    ctx->pc = 0x136244u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x136248: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x136248u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x13624c: 0x2675fffc  addiu       $s5, $s3, -0x4
    ctx->pc = 0x13624cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x136250: 0x118100  sll         $s0, $s1, 4
    ctx->pc = 0x136250u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x136254: 0x0  nop
    ctx->pc = 0x136254u;
    // NOP
label_136258:
    // 0x136258: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x136258u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13625c: 0x2132821  addu        $a1, $s0, $s3
    ctx->pc = 0x13625cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x136260: 0x2158021  addu        $s0, $s0, $s5
    ctx->pc = 0x136260u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
    // 0x136264: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136268: 0xc042d10  jal         func_10B440
    ctx->pc = 0x136268u;
    SET_GPR_U32(ctx, 31, 0x136270u);
    ctx->pc = 0x13626Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136268u;
            // 0x13626c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136270u; }
        if (ctx->pc != 0x136270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136270u; }
        if (ctx->pc != 0x136270u) { return; }
    }
    ctx->pc = 0x136270u;
label_136270:
    // 0x136270: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x136270u;
    {
        const bool branch_taken_0x136270 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x136270) {
            ctx->pc = 0x136274u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136270u;
            // 0x136274: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1362B4u;
            goto label_1362b4;
        }
    }
    ctx->pc = 0x136278u;
    // 0x136278: 0x8e100000  lw          $s0, 0x0($s0)
    ctx->pc = 0x136278u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13627c: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13627Cu;
    {
        const bool branch_taken_0x13627c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x136280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13627Cu;
            // 0x136280: 0x26c4bc80  addiu       $a0, $s6, -0x4380 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294950016));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13627c) {
            ctx->pc = 0x1362A0u;
            goto label_1362a0;
        }
    }
    ctx->pc = 0x136284u;
    // 0x136284: 0x8e10000c  lw          $s0, 0xC($s0)
    ctx->pc = 0x136284u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x136288: 0x5200000a  beql        $s0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x136288u;
    {
        const bool branch_taken_0x136288 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x136288) {
            ctx->pc = 0x13628Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136288u;
            // 0x13628c: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1362B4u;
            goto label_1362b4;
        }
    }
    ctx->pc = 0x136290u;
    // 0x136290: 0x200f809  jalr        $s0
    ctx->pc = 0x136290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 16);
        SET_GPR_U32(ctx, 31, 0x136298u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136298u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136298u; }
            if (ctx->pc != 0x136298u) { return; }
        }
        }
    }
    ctx->pc = 0x136298u;
label_136298:
    // 0x136298: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x136298u;
    {
        const bool branch_taken_0x136298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13629Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136298u;
            // 0x13629c: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136298) {
            ctx->pc = 0x1362B0u;
            goto label_1362b0;
        }
    }
    ctx->pc = 0x1362A0u;
label_1362a0:
    // 0x1362a0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1362A0u;
    SET_GPR_U32(ctx, 31, 0x1362A8u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1362A8u; }
        if (ctx->pc != 0x1362A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1362A8u; }
        if (ctx->pc != 0x1362A8u) { return; }
    }
    ctx->pc = 0x1362A8u;
label_1362a8:
    // 0x1362a8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1362A8u;
    {
        const bool branch_taken_0x1362a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1362ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362A8u;
            // 0x1362ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1362a8) {
            ctx->pc = 0x1362C0u;
            goto label_1362c0;
        }
    }
    ctx->pc = 0x1362B0u;
label_1362b0:
    // 0x1362b0: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x1362b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
label_1362b4:
    // 0x1362b4: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1362B4u;
    {
        const bool branch_taken_0x1362b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1362B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362B4u;
            // 0x1362b8: 0x118100  sll         $s0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1362b4) {
            ctx->pc = 0x136258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_136258;
        }
    }
    ctx->pc = 0x1362BCu;
    // 0x1362bc: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x1362bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1362c0:
    // 0x1362c0: 0xdfb00130  ld          $s0, 0x130($sp)
    ctx->pc = 0x1362c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1362c4: 0xdfb10138  ld          $s1, 0x138($sp)
    ctx->pc = 0x1362c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 312)));
    // 0x1362c8: 0xdfb20140  ld          $s2, 0x140($sp)
    ctx->pc = 0x1362c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x1362cc: 0xdfb30148  ld          $s3, 0x148($sp)
    ctx->pc = 0x1362ccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 328)));
    // 0x1362d0: 0xdfb40150  ld          $s4, 0x150($sp)
    ctx->pc = 0x1362d0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 336)));
    // 0x1362d4: 0xdfb50158  ld          $s5, 0x158($sp)
    ctx->pc = 0x1362d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 344)));
    // 0x1362d8: 0xdfb60160  ld          $s6, 0x160($sp)
    ctx->pc = 0x1362d8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x1362dc: 0xdfbf0168  ld          $ra, 0x168($sp)
    ctx->pc = 0x1362dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 360)));
    // 0x1362e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1362E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1362E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362E0u;
            // 0x1362e4: 0x27bd0170  addiu       $sp, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1362E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
