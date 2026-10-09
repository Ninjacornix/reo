#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176210
// Address: 0x176210 - 0x176338
void sub_00176210_0x176210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176210_0x176210");
#endif

    switch (ctx->pc) {
        case 0x176244u: goto label_176244;
        case 0x17628cu: goto label_17628c;
        case 0x1762e4u: goto label_1762e4;
        default: break;
    }

    ctx->pc = 0x176210u;

    // 0x176210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x176210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x176214: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x176214u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176218: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17621c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x17621cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176220: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176224: 0x24510da4  addiu       $s1, $v0, 0xDA4
    ctx->pc = 0x176224u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 3492));
    // 0x176228: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x176228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17622c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x17622cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176230: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x176230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x176234: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x176234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x176238: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x176238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x17623c: 0xc05d8ce  jal         func_176338
    ctx->pc = 0x17623Cu;
    SET_GPR_U32(ctx, 31, 0x176244u);
    ctx->pc = 0x176240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17623Cu;
            // 0x176240: 0x24530cc0  addiu       $s3, $v0, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 3264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176338u;
    if (runtime->hasFunction(0x176338u)) {
        auto targetFn = runtime->lookupFunction(0x176338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176244u; }
        if (ctx->pc != 0x176244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176338_0x176338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176244u; }
        if (ctx->pc != 0x176244u) { return; }
    }
    ctx->pc = 0x176244u;
label_176244:
    // 0x176244: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x176244u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x176248: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x176248u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17624c: 0x10a30013  beq         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x17624Cu;
    {
        const bool branch_taken_0x17624c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x176250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17624Cu;
            // 0x176250: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17624c) {
            ctx->pc = 0x17629Cu;
            goto label_17629c;
        }
    }
    ctx->pc = 0x176254u;
    // 0x176254: 0x8e620110  lw          $v0, 0x110($s3)
    ctx->pc = 0x176254u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 272)));
    // 0x176258: 0x54a20007  bnel        $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x176258u;
    {
        const bool branch_taken_0x176258 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x176258) {
            ctx->pc = 0x17625Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176258u;
            // 0x17625c: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x176278u;
            goto label_176278;
        }
    }
    ctx->pc = 0x176260u;
    // 0x176260: 0x8e63010c  lw          $v1, 0x10C($s3)
    ctx->pc = 0x176260u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 268)));
    // 0x176264: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x176264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x176268: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176268u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17626c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x17626Cu;
    {
        const bool branch_taken_0x17626c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x176270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17626Cu;
            // 0x176270: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17626c) {
            ctx->pc = 0x176298u;
            goto label_176298;
        }
    }
    ctx->pc = 0x176274u;
    // 0x176274: 0x0  nop
    ctx->pc = 0x176274u;
    // NOP
label_176278:
    // 0x176278: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x176278u;
    {
        const bool branch_taken_0x176278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x176278) {
            ctx->pc = 0x17627Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176278u;
            // 0x17627c: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17629Cu;
            goto label_17629c;
        }
    }
    ctx->pc = 0x176280u;
    // 0x176280: 0x8e260024  lw          $a2, 0x24($s1)
    ctx->pc = 0x176280u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x176284: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x176284u;
    SET_GPR_U32(ctx, 31, 0x17628Cu);
    ctx->pc = 0x176288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176284u;
            // 0x176288: 0x8e240020  lw          $a0, 0x20($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17628Cu; }
        if (ctx->pc != 0x17628Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17628Cu; }
        if (ctx->pc != 0x17628Cu) { return; }
    }
    ctx->pc = 0x17628Cu;
label_17628c:
    // 0x17628c: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x17628cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x176290: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x176290u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x176294: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x176294u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_176298:
    // 0x176298: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x176298u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_17629c:
    // 0x17629c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17629cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1762a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1762a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1762a4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1762a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1762a8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1762a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1762ac: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1762acu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1762b0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1762b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1762b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1762B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1762B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1762B4u;
            // 0x1762b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176244u: goto label_176244;
            case 0x176278u: goto label_176278;
            case 0x17628Cu: goto label_17628c;
            case 0x176298u: goto label_176298;
            case 0x17629Cu: goto label_17629c;
            case 0x1762E4u: goto label_1762e4;
            case 0x176318u: goto label_176318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1762BCu;
    // 0x1762bc: 0x0  nop
    ctx->pc = 0x1762bcu;
    // NOP
    // 0x1762c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1762c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1762c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1762c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1762c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1762c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1762ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1762d0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1762d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1762d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1762d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1762d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1762dc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1762DCu;
    SET_GPR_U32(ctx, 31, 0x1762E4u);
    ctx->pc = 0x1762E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1762DCu;
            // 0x1762e0: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1762E4u; }
        if (ctx->pc != 0x1762E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1762E4u; }
        if (ctx->pc != 0x1762E4u) { return; }
    }
    ctx->pc = 0x1762E4u;
label_1762e4:
    // 0x1762e4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1762e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1762e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1762e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762ec: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1762ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762f0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1762F0u;
    {
        const bool branch_taken_0x1762f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1762F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1762F0u;
            // 0x1762f4: 0x34a50127  ori         $a1, $a1, 0x127 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)295);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1762f0) {
            ctx->pc = 0x176318u;
            goto label_176318;
        }
    }
    ctx->pc = 0x1762F8u;
    // 0x1762f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1762f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1762fc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1762fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176300: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176300u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176304: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x176304u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176308: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17630c: 0x805a704  j           func_169C10
    ctx->pc = 0x17630Cu;
    ctx->pc = 0x176310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17630Cu;
            // 0x176310: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176314u;
    // 0x176314: 0x0  nop
    ctx->pc = 0x176314u;
    // NOP
label_176318:
    // 0x176318: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x176318u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17631c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17631cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176320: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176320u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176324: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176324u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176328: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17632c: 0x805d8ce  j           func_176338
    ctx->pc = 0x17632Cu;
    ctx->pc = 0x176330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17632Cu;
            // 0x176330: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176338u;
    if (runtime->hasFunction(0x176338u)) {
        auto targetFn = runtime->lookupFunction(0x176338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176338_0x176338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176334u;
    // 0x176334: 0x0  nop
    ctx->pc = 0x176334u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
