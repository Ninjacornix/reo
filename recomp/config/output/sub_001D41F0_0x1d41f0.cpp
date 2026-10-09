#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D41F0
// Address: 0x1d41f0 - 0x1d4570
void sub_001D41F0_0x1d41f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D41F0_0x1d41f0");
#endif

    switch (ctx->pc) {
        case 0x1d4218u: goto label_1d4218;
        case 0x1d4234u: goto label_1d4234;
        case 0x1d4250u: goto label_1d4250;
        case 0x1d429cu: goto label_1d429c;
        case 0x1d42dcu: goto label_1d42dc;
        case 0x1d42f4u: goto label_1d42f4;
        case 0x1d4308u: goto label_1d4308;
        case 0x1d4360u: goto label_1d4360;
        case 0x1d4380u: goto label_1d4380;
        case 0x1d43a0u: goto label_1d43a0;
        case 0x1d43c0u: goto label_1d43c0;
        case 0x1d43dcu: goto label_1d43dc;
        case 0x1d4428u: goto label_1d4428;
        case 0x1d4468u: goto label_1d4468;
        case 0x1d4480u: goto label_1d4480;
        case 0x1d4494u: goto label_1d4494;
        case 0x1d44ecu: goto label_1d44ec;
        case 0x1d450cu: goto label_1d450c;
        case 0x1d4528u: goto label_1d4528;
        case 0x1d4548u: goto label_1d4548;
        default: break;
    }

    ctx->pc = 0x1d41f0u;

    // 0x1d41f0: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x1d41f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x1d41f4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d41f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d41f8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d41f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d41fc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d41fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d4200: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d4200u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4204: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4204u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4208: 0x3c120032  lui         $s2, 0x32
    ctx->pc = 0x1d4208u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)50 << 16));
    // 0x1d420c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d420cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4210: 0xc1adcfc  jal         func_6B73F0
    ctx->pc = 0x1D4210u;
    SET_GPR_U32(ctx, 31, 0x1D4218u);
    ctx->pc = 0x1D4214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4210u;
            // 0x1d4214: 0x265243c0  addiu       $s2, $s2, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 17344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B73F0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B73F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4218u; }
        if (ctx->pc != 0x1D4218u) { return; }
    }
    ctx->pc = 0x1D4218u;
label_1d4218:
    // 0x1d4218: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d4218u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d421c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1d421cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4220: 0x90239d14  lbu         $v1, -0x62EC($at)
    ctx->pc = 0x1d4220u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294941972)));
    // 0x1d4224: 0x107100ca  beq         $v1, $s1, . + 4 + (0xCA << 2)
    ctx->pc = 0x1D4224u;
    {
        const bool branch_taken_0x1d4224 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 17));
        if (branch_taken_0x1d4224) {
            ctx->pc = 0x1D4550u;
            goto label_1d4550;
        }
    }
    ctx->pc = 0x1D422Cu;
    // 0x1d422c: 0xc1addc8  jal         func_6B7720
    ctx->pc = 0x1D422Cu;
    SET_GPR_U32(ctx, 31, 0x1D4234u);
    ctx->pc = 0x6B7720u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4234u; }
        if (ctx->pc != 0x1D4234u) { return; }
    }
    ctx->pc = 0x1D4234u;
label_1d4234:
    // 0x1d4234: 0x62000c6  bltz        $s1, . + 4 + (0xC6 << 2)
    ctx->pc = 0x1D4234u;
    {
        const bool branch_taken_0x1d4234 = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x1D4238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4234u;
            // 0x1d4238: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4234) {
            ctx->pc = 0x1D4550u;
            goto label_1d4550;
        }
    }
    ctx->pc = 0x1D423Cu;
    // 0x1d423c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1d423cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4240: 0x8c224438  lw          $v0, 0x4438($at)
    ctx->pc = 0x1d4240u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d4244: 0x27b00060  addiu       $s0, $sp, 0x60
    ctx->pc = 0x1d4244u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4248: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1D4248u;
    {
        const bool branch_taken_0x1d4248 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D424Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4248u;
            // 0x1d424c: 0x24536000  addiu       $s3, $v0, 0x6000 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 24576));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4248) {
            ctx->pc = 0x1D4318u;
            goto label_1d4318;
        }
    }
    ctx->pc = 0x1D4250u;
label_1d4250:
    // 0x1d4250: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d4250u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4254: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1D4254u;
    {
        const bool branch_taken_0x1d4254 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4254u;
            // 0x1d4258: 0x141100  sll         $v0, $s4, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4254) {
            ctx->pc = 0x1D42A4u;
            goto label_1d42a4;
        }
    }
    ctx->pc = 0x1D425Cu;
    // 0x1d425c: 0x141100  sll         $v0, $s4, 4
    ctx->pc = 0x1d425cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 4));
    // 0x1d4260: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d4260u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d4264: 0x542823  subu        $a1, $v0, $s4
    ctx->pc = 0x1d4264u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1d4268: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d4268u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d426c: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1d426cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d4270: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1d4270u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1d4274: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1d4274u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d4278: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1d4278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d427c: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1d427cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d4280: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4280u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4284: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4288: 0x24a567d0  addiu       $a1, $a1, 0x67D0
    ctx->pc = 0x1d4288u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26576));
    // 0x1d428c: 0x90490b98  lbu         $t1, 0xB98($v0)
    ctx->pc = 0x1d428cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d4290: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1d4290u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4294: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4294u;
    SET_GPR_U32(ctx, 31, 0x1D429Cu);
    ctx->pc = 0x1D4298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4294u;
            // 0x1d4298: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D429Cu; }
        if (ctx->pc != 0x1D429Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D429Cu; }
        if (ctx->pc != 0x1D429Cu) { return; }
    }
    ctx->pc = 0x1D429Cu;
label_1d429c:
    // 0x1d429c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D429Cu;
    {
        const bool branch_taken_0x1d429c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D42A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D429Cu;
            // 0x1d42a0: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d429c) {
            ctx->pc = 0x1D42E0u;
            goto label_1d42e0;
        }
    }
    ctx->pc = 0x1D42A4u;
label_1d42a4:
    // 0x1d42a4: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d42a4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d42a8: 0x542823  subu        $a1, $v0, $s4
    ctx->pc = 0x1d42a8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1d42ac: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d42acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d42b0: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1d42b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d42b4: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1d42b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1d42b8: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1d42b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d42bc: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1d42bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d42c0: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1d42c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d42c4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d42c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d42c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d42c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d42cc: 0x24a56800  addiu       $a1, $a1, 0x6800
    ctx->pc = 0x1d42ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26624));
    // 0x1d42d0: 0x90480b98  lbu         $t0, 0xB98($v0)
    ctx->pc = 0x1d42d0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d42d4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D42D4u;
    SET_GPR_U32(ctx, 31, 0x1D42DCu);
    ctx->pc = 0x1D42D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D42D4u;
            // 0x1d42d8: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D42DCu; }
        if (ctx->pc != 0x1D42DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D42DCu; }
        if (ctx->pc != 0x1D42DCu) { return; }
    }
    ctx->pc = 0x1D42DCu;
label_1d42dc:
    // 0x1d42dc: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d42dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
label_1d42e0:
    // 0x1d42e0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d42e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d42e4: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d42e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d42e8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d42e8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d42ec: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D42ECu;
    SET_GPR_U32(ctx, 31, 0x1D42F4u);
    ctx->pc = 0x1D42F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D42ECu;
            // 0x1d42f0: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D42F4u; }
        if (ctx->pc != 0x1D42F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D42F4u; }
        if (ctx->pc != 0x1D42F4u) { return; }
    }
    ctx->pc = 0x1D42F4u;
label_1d42f4:
    // 0x1d42f4: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D42F4u;
    {
        const bool branch_taken_0x1d42f4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D42F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D42F4u;
            // 0x1d42f8: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d42f4) {
            ctx->pc = 0x1D4308u;
            goto label_1d4308;
        }
    }
    ctx->pc = 0x1D42FCu;
    // 0x1d42fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d42fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4300: 0xc1adcd4  jal         func_6B7350
    ctx->pc = 0x1D4300u;
    SET_GPR_U32(ctx, 31, 0x1D4308u);
    ctx->pc = 0x1D4304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4300u;
            // 0x1d4304: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4308u; }
        if (ctx->pc != 0x1D4308u) { return; }
    }
    ctx->pc = 0x1D4308u;
label_1d4308:
    // 0x1d4308: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4308u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d430c: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1d430cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d4310: 0x34422800  ori         $v0, $v0, 0x2800
    ctx->pc = 0x1d4310u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)10240);
    // 0x1d4314: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1d4314u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
label_1d4318:
    // 0x1d4318: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d4318u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d431c: 0x8c22aea0  lw          $v0, -0x5160($at)
    ctx->pc = 0x1d431cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294946464)));
    // 0x1d4320: 0x282102a  slt         $v0, $s4, $v0
    ctx->pc = 0x1d4320u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d4324: 0x1440ffca  bnez        $v0, . + 4 + (-0x36 << 2)
    ctx->pc = 0x1D4324u;
    {
        const bool branch_taken_0x1d4324 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4324u;
            // 0x1d4328: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4324) {
            ctx->pc = 0x1D4250u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d4250;
        }
    }
    ctx->pc = 0x1D432Cu;
    // 0x1d432c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d432cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4330: 0x8c234438  lw          $v1, 0x4438($at)
    ctx->pc = 0x1d4330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d4334: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4334u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4338: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d4338u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d433c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D433Cu;
    {
        const bool branch_taken_0x1d433c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D433Cu;
            // 0x1d4340: 0x24736000  addiu       $s3, $v1, 0x6000 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 24576));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d433c) {
            ctx->pc = 0x1D4368u;
            goto label_1d4368;
        }
    }
    ctx->pc = 0x1D4344u;
    // 0x1d4344: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d4344u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d4348: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4348u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d434c: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d434cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4350: 0x24a56820  addiu       $a1, $a1, 0x6820
    ctx->pc = 0x1d4350u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26656));
    // 0x1d4354: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1d4354u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4358: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4358u;
    SET_GPR_U32(ctx, 31, 0x1D4360u);
    ctx->pc = 0x1D435Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4358u;
            // 0x1d435c: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4360u; }
        if (ctx->pc != 0x1D4360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4360u; }
        if (ctx->pc != 0x1D4360u) { return; }
    }
    ctx->pc = 0x1D4360u;
label_1d4360:
    // 0x1d4360: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D4360u;
    {
        const bool branch_taken_0x1d4360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4360u;
            // 0x1d4364: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4360) {
            ctx->pc = 0x1D4384u;
            goto label_1d4384;
        }
    }
    ctx->pc = 0x1D4368u;
label_1d4368:
    // 0x1d4368: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d4368u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d436c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d436cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4370: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d4370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4374: 0x24a56850  addiu       $a1, $a1, 0x6850
    ctx->pc = 0x1d4374u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26704));
    // 0x1d4378: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4378u;
    SET_GPR_U32(ctx, 31, 0x1D4380u);
    ctx->pc = 0x1D437Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4378u;
            // 0x1d437c: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4380u; }
        if (ctx->pc != 0x1D4380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4380u; }
        if (ctx->pc != 0x1D4380u) { return; }
    }
    ctx->pc = 0x1D4380u;
label_1d4380:
    // 0x1d4380: 0x3c020004  lui         $v0, 0x4
    ctx->pc = 0x1d4380u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
label_1d4384:
    // 0x1d4384: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d4384u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4388: 0x3443a000  ori         $v1, $v0, 0xA000
    ctx->pc = 0x1d4388u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x1d438c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d438cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4390: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4394: 0x2632821  addu        $a1, $s3, $v1
    ctx->pc = 0x1d4394u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1d4398: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4398u;
    SET_GPR_U32(ctx, 31, 0x1D43A0u);
    ctx->pc = 0x1D439Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4398u;
            // 0x1d439c: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D43A0u; }
        if (ctx->pc != 0x1D43A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D43A0u; }
        if (ctx->pc != 0x1D43A0u) { return; }
    }
    ctx->pc = 0x1D43A0u;
label_1d43a0:
    // 0x1d43a0: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D43A0u;
    {
        const bool branch_taken_0x1d43a0 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d43a0) {
            ctx->pc = 0x1D43C0u;
            goto label_1d43c0;
        }
    }
    ctx->pc = 0x1D43A8u;
    // 0x1d43a8: 0x3c020004  lui         $v0, 0x4
    ctx->pc = 0x1d43a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
    // 0x1d43ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d43acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d43b0: 0x3442a000  ori         $v0, $v0, 0xA000
    ctx->pc = 0x1d43b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x1d43b4: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1d43b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d43b8: 0xc1adcd4  jal         func_6B7350
    ctx->pc = 0x1D43B8u;
    SET_GPR_U32(ctx, 31, 0x1D43C0u);
    ctx->pc = 0x1D43BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D43B8u;
            // 0x1d43bc: 0x2622021  addu        $a0, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D43C0u; }
        if (ctx->pc != 0x1D43C0u) { return; }
    }
    ctx->pc = 0x1D43C0u;
label_1d43c0:
    // 0x1d43c0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d43c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d43c4: 0x3c020005  lui         $v0, 0x5
    ctx->pc = 0x1d43c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)5 << 16));
    // 0x1d43c8: 0x8c234438  lw          $v1, 0x4438($at)
    ctx->pc = 0x1d43c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d43cc: 0x3442c000  ori         $v0, $v0, 0xC000
    ctx->pc = 0x1d43ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49152);
    // 0x1d43d0: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d43d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d43d4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1D43D4u;
    {
        const bool branch_taken_0x1d43d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D43D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D43D4u;
            // 0x1d43d8: 0x62a021  addu        $s4, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d43d4) {
            ctx->pc = 0x1D449Cu;
            goto label_1d449c;
        }
    }
    ctx->pc = 0x1D43DCu;
label_1d43dc:
    // 0x1d43dc: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d43dcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d43e0: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1D43E0u;
    {
        const bool branch_taken_0x1d43e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D43E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D43E0u;
            // 0x1d43e4: 0x131100  sll         $v0, $s3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d43e0) {
            ctx->pc = 0x1D4430u;
            goto label_1d4430;
        }
    }
    ctx->pc = 0x1D43E8u;
    // 0x1d43e8: 0x131100  sll         $v0, $s3, 4
    ctx->pc = 0x1d43e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
    // 0x1d43ec: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d43ecu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d43f0: 0x532823  subu        $a1, $v0, $s3
    ctx->pc = 0x1d43f0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d43f4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d43f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d43f8: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1d43f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d43fc: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1d43fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1d4400: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1d4400u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d4404: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1d4404u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d4408: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1d4408u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d440c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d440cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4410: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4410u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4414: 0x24a56870  addiu       $a1, $a1, 0x6870
    ctx->pc = 0x1d4414u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26736));
    // 0x1d4418: 0x90490b98  lbu         $t1, 0xB98($v0)
    ctx->pc = 0x1d4418u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d441c: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1d441cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4420: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4420u;
    SET_GPR_U32(ctx, 31, 0x1D4428u);
    ctx->pc = 0x1D4424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4420u;
            // 0x1d4424: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4428u; }
        if (ctx->pc != 0x1D4428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4428u; }
        if (ctx->pc != 0x1D4428u) { return; }
    }
    ctx->pc = 0x1D4428u;
label_1d4428:
    // 0x1d4428: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D4428u;
    {
        const bool branch_taken_0x1d4428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D442Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4428u;
            // 0x1d442c: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4428) {
            ctx->pc = 0x1D446Cu;
            goto label_1d446c;
        }
    }
    ctx->pc = 0x1D4430u;
label_1d4430:
    // 0x1d4430: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d4430u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d4434: 0x532823  subu        $a1, $v0, $s3
    ctx->pc = 0x1d4434u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d4438: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d4438u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d443c: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1d443cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d4440: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1d4440u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1d4444: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1d4444u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d4448: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1d4448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d444c: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1d444cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d4450: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4450u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4454: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4454u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4458: 0x24a568a0  addiu       $a1, $a1, 0x68A0
    ctx->pc = 0x1d4458u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26784));
    // 0x1d445c: 0x90480b98  lbu         $t0, 0xB98($v0)
    ctx->pc = 0x1d445cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d4460: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4460u;
    SET_GPR_U32(ctx, 31, 0x1D4468u);
    ctx->pc = 0x1D4464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4460u;
            // 0x1d4464: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4468u; }
        if (ctx->pc != 0x1D4468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4468u; }
        if (ctx->pc != 0x1D4468u) { return; }
    }
    ctx->pc = 0x1D4468u;
label_1d4468:
    // 0x1d4468: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4468u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
label_1d446c:
    // 0x1d446c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d446cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4470: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d4470u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4474: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d4474u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4478: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4478u;
    SET_GPR_U32(ctx, 31, 0x1D4480u);
    ctx->pc = 0x1D447Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4478u;
            // 0x1d447c: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4480u; }
        if (ctx->pc != 0x1D4480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4480u; }
        if (ctx->pc != 0x1D4480u) { return; }
    }
    ctx->pc = 0x1D4480u;
label_1d4480:
    // 0x1d4480: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4480u;
    {
        const bool branch_taken_0x1d4480 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D4484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4480u;
            // 0x1d4484: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4480) {
            ctx->pc = 0x1D4494u;
            goto label_1d4494;
        }
    }
    ctx->pc = 0x1D4488u;
    // 0x1d4488: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d4488u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d448c: 0xc1adcd4  jal         func_6B7350
    ctx->pc = 0x1D448Cu;
    SET_GPR_U32(ctx, 31, 0x1D4494u);
    ctx->pc = 0x1D4490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D448Cu;
            // 0x1d4490: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4494u; }
        if (ctx->pc != 0x1D4494u) { return; }
    }
    ctx->pc = 0x1D4494u;
label_1d4494:
    // 0x1d4494: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d4494u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d4498: 0x26945c00  addiu       $s4, $s4, 0x5C00
    ctx->pc = 0x1d4498u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 23552));
label_1d449c:
    // 0x1d449c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d449cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d44a0: 0x8c22aea0  lw          $v0, -0x5160($at)
    ctx->pc = 0x1d44a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294946464)));
    // 0x1d44a4: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x1d44a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d44a8: 0x1440ffcc  bnez        $v0, . + 4 + (-0x34 << 2)
    ctx->pc = 0x1D44A8u;
    {
        const bool branch_taken_0x1d44a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D44ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D44A8u;
            // 0x1d44ac: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d44a8) {
            ctx->pc = 0x1D43DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d43dc;
        }
    }
    ctx->pc = 0x1D44B0u;
    // 0x1d44b0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d44b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d44b4: 0x3c020005  lui         $v0, 0x5
    ctx->pc = 0x1d44b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)5 << 16));
    // 0x1d44b8: 0x8c244438  lw          $a0, 0x4438($at)
    ctx->pc = 0x1d44b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d44bc: 0x3443c000  ori         $v1, $v0, 0xC000
    ctx->pc = 0x1d44bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49152);
    // 0x1d44c0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d44c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d44c4: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d44c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d44c8: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D44C8u;
    {
        const bool branch_taken_0x1d44c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D44CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D44C8u;
            // 0x1d44cc: 0x839821  addu        $s3, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d44c8) {
            ctx->pc = 0x1D44F4u;
            goto label_1d44f4;
        }
    }
    ctx->pc = 0x1D44D0u;
    // 0x1d44d0: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d44d0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d44d4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d44d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d44d8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d44d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d44dc: 0x24a568c0  addiu       $a1, $a1, 0x68C0
    ctx->pc = 0x1d44dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26816));
    // 0x1d44e0: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1d44e0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d44e4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D44E4u;
    SET_GPR_U32(ctx, 31, 0x1D44ECu);
    ctx->pc = 0x1D44E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D44E4u;
            // 0x1d44e8: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D44ECu; }
        if (ctx->pc != 0x1D44ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D44ECu; }
        if (ctx->pc != 0x1D44ECu) { return; }
    }
    ctx->pc = 0x1D44ECu;
label_1d44ec:
    // 0x1d44ec: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D44ECu;
    {
        const bool branch_taken_0x1d44ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D44F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D44ECu;
            // 0x1d44f0: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d44ec) {
            ctx->pc = 0x1D4510u;
            goto label_1d4510;
        }
    }
    ctx->pc = 0x1D44F4u;
label_1d44f4:
    // 0x1d44f4: 0x9646001a  lhu         $a2, 0x1A($s2)
    ctx->pc = 0x1d44f4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d44f8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d44f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d44fc: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d44fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4500: 0x24a568f0  addiu       $a1, $a1, 0x68F0
    ctx->pc = 0x1d4500u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26864));
    // 0x1d4504: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4504u;
    SET_GPR_U32(ctx, 31, 0x1D450Cu);
    ctx->pc = 0x1D4508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4504u;
            // 0x1d4508: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D450Cu; }
        if (ctx->pc != 0x1D450Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D450Cu; }
        if (ctx->pc != 0x1D450Cu) { return; }
    }
    ctx->pc = 0x1D450Cu;
label_1d450c:
    // 0x1d450c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d450cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
label_1d4510:
    // 0x1d4510: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d4510u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4514: 0x34437000  ori         $v1, $v0, 0x7000
    ctx->pc = 0x1d4514u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)28672);
    // 0x1d4518: 0x34460001  ori         $a2, $v0, 0x1
    ctx->pc = 0x1d4518u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x1d451c: 0x2632821  addu        $a1, $s3, $v1
    ctx->pc = 0x1d451cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1d4520: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4520u;
    SET_GPR_U32(ctx, 31, 0x1D4528u);
    ctx->pc = 0x1D4524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4520u;
            // 0x1d4524: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4528u; }
        if (ctx->pc != 0x1D4528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4528u; }
        if (ctx->pc != 0x1D4528u) { return; }
    }
    ctx->pc = 0x1D4528u;
label_1d4528:
    // 0x1d4528: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D4528u;
    {
        const bool branch_taken_0x1d4528 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d4528) {
            ctx->pc = 0x1D4548u;
            goto label_1d4548;
        }
    }
    ctx->pc = 0x1D4530u;
    // 0x1d4530: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4530u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4534: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d4534u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4538: 0x34427000  ori         $v0, $v0, 0x7000
    ctx->pc = 0x1d4538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)28672);
    // 0x1d453c: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1d453cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d4540: 0xc1adcd4  jal         func_6B7350
    ctx->pc = 0x1D4540u;
    SET_GPR_U32(ctx, 31, 0x1D4548u);
    ctx->pc = 0x1D4544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4540u;
            // 0x1d4544: 0x2622021  addu        $a0, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4548u; }
        if (ctx->pc != 0x1D4548u) { return; }
    }
    ctx->pc = 0x1D4548u;
label_1d4548:
    // 0x1d4548: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d4548u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d454c: 0xa0319d14  sb          $s1, -0x62EC($at)
    ctx->pc = 0x1d454cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294941972), (uint8_t)GPR_U32(ctx, 17));
label_1d4550:
    // 0x1d4550: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d4550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d4554: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d4554u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d4558: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d4558u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d455c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d455cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4560: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d4560u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4564: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4564u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4568: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D456Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4568u;
            // 0x1d456c: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4218u: goto label_1d4218;
            case 0x1D4234u: goto label_1d4234;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D429Cu: goto label_1d429c;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42DCu: goto label_1d42dc;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D42F4u: goto label_1d42f4;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4360u: goto label_1d4360;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4380u: goto label_1d4380;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43A0u: goto label_1d43a0;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4428u: goto label_1d4428;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D4468u: goto label_1d4468;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4480u: goto label_1d4480;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44ECu: goto label_1d44ec;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D450Cu: goto label_1d450c;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4528u: goto label_1d4528;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4570u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
