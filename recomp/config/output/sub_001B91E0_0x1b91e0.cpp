#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B91E0
// Address: 0x1b91e0 - 0x1b93b0
void sub_001B91E0_0x1b91e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B91E0_0x1b91e0");
#endif

    switch (ctx->pc) {
        case 0x1b9254u: goto label_1b9254;
        case 0x1b9290u: goto label_1b9290;
        case 0x1b934cu: goto label_1b934c;
        case 0x1b937cu: goto label_1b937c;
        case 0x1b939cu: goto label_1b939c;
        default: break;
    }

    ctx->pc = 0x1b91e0u;

    // 0x1b91e0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1b91e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1b91e4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b91e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b91e8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b91e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b91ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b91ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b91f0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b91f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b91f4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b91f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b91f8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b91f8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b91fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b91fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9200: 0x12600023  beqz        $s3, . + 4 + (0x23 << 2)
    ctx->pc = 0x1B9200u;
    {
        const bool branch_taken_0x1b9200 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9200u;
            // 0x1b9204: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9200) {
            ctx->pc = 0x1B9290u;
            goto label_1b9290;
        }
    }
    ctx->pc = 0x1B9208u;
    // 0x1b9208: 0x92850002  lbu         $a1, 0x2($s4)
    ctx->pc = 0x1b9208u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 2)));
    // 0x1b920c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b920cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b9210: 0x10a30014  beq         $a1, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B9210u;
    {
        const bool branch_taken_0x1b9210 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B9214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9210u;
            // 0x1b9214: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9210) {
            ctx->pc = 0x1B9264u;
            goto label_1b9264;
        }
    }
    ctx->pc = 0x1B9218u;
    // 0x1b9218: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b9218u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b921c: 0x10a30011  beq         $a1, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B921Cu;
    {
        const bool branch_taken_0x1b921c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b921c) {
            ctx->pc = 0x1B9264u;
            goto label_1b9264;
        }
    }
    ctx->pc = 0x1B9224u;
    // 0x1b9224: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9228: 0x10a40019  beq         $a1, $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1B9228u;
    {
        const bool branch_taken_0x1b9228 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        if (branch_taken_0x1b9228) {
            ctx->pc = 0x1B9290u;
            goto label_1b9290;
        }
    }
    ctx->pc = 0x1B9230u;
    // 0x1b9230: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9230u;
    {
        const bool branch_taken_0x1b9230 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9230) {
            ctx->pc = 0x1B9240u;
            goto label_1b9240;
        }
    }
    ctx->pc = 0x1B9238u;
    // 0x1b9238: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B9238u;
    {
        const bool branch_taken_0x1b9238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B923Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9238u;
            // 0x1b923c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9238) {
            ctx->pc = 0x1B9274u;
            goto label_1b9274;
        }
    }
    ctx->pc = 0x1B9240u;
label_1b9240:
    // 0x1b9240: 0x92910003  lbu         $s1, 0x3($s4)
    ctx->pc = 0x1b9240u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 3)));
    // 0x1b9244: 0x14c4000a  bne         $a2, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B9244u;
    {
        const bool branch_taken_0x1b9244 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        ctx->pc = 0x1B9248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9244u;
            // 0x1b9248: 0x26320008  addiu       $s2, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9244) {
            ctx->pc = 0x1B9270u;
            goto label_1b9270;
        }
    }
    ctx->pc = 0x1B924Cu;
    // 0x1b924c: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B924Cu;
    SET_GPR_U32(ctx, 31, 0x1B9254u);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9254u; }
        if (ctx->pc != 0x1B9254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9254u; }
        if (ctx->pc != 0x1B9254u) { return; }
    }
    ctx->pc = 0x1B9254u;
label_1b9254:
    // 0x1b9254: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1b9254u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b9258: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1b9258u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1b925c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B925Cu;
    {
        const bool branch_taken_0x1b925c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B925Cu;
            // 0x1b9260: 0x2629821  addu        $s3, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b925c) {
            ctx->pc = 0x1B9270u;
            goto label_1b9270;
        }
    }
    ctx->pc = 0x1B9264u;
label_1b9264:
    // 0x1b9264: 0x92910554  lbu         $s1, 0x554($s4)
    ctx->pc = 0x1b9264u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1364)));
    // 0x1b9268: 0x2412000c  addiu       $s2, $zero, 0xC
    ctx->pc = 0x1b9268u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1b926c: 0x92900033  lbu         $s0, 0x33($s4)
    ctx->pc = 0x1b926cu;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 51)));
label_1b9270:
    // 0x1b9270: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b9270u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1b9274:
    // 0x1b9274: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1b9274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9278: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1b9278u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b927c: 0x26870038  addiu       $a3, $s4, 0x38
    ctx->pc = 0x1b927cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 20), 56));
    // 0x1b9280: 0x200502d  daddu       $t2, $s0, $zero
    ctx->pc = 0x1b9280u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9284: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9284u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9288: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9288u;
    SET_GPR_U32(ctx, 31, 0x1B9290u);
    ctx->pc = 0x1B928Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9288u;
            // 0x1b928c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9290u; }
        if (ctx->pc != 0x1B9290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9290u; }
        if (ctx->pc != 0x1B9290u) { return; }
    }
    ctx->pc = 0x1B9290u;
label_1b9290:
    // 0x1b9290: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b9290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b9294: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b9294u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b9298: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b9298u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b929c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b929cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b92a0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b92a0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b92a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b92a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b92a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B92A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B92ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B92A8u;
            // 0x1b92ac: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9240u: goto label_1b9240;
            case 0x1B9254u: goto label_1b9254;
            case 0x1B9264u: goto label_1b9264;
            case 0x1B9270u: goto label_1b9270;
            case 0x1B9274u: goto label_1b9274;
            case 0x1B9290u: goto label_1b9290;
            case 0x1B9330u: goto label_1b9330;
            case 0x1B934Cu: goto label_1b934c;
            case 0x1B937Cu: goto label_1b937c;
            case 0x1B9384u: goto label_1b9384;
            case 0x1B939Cu: goto label_1b939c;
            case 0x1B93A0u: goto label_1b93a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B92B0u;
    // 0x1b92b0: 0x94820bba  lhu         $v0, 0xBBA($a0)
    ctx->pc = 0x1b92b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 3002)));
    // 0x1b92b4: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1b92b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1b92b8: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x1b92b8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1b92bc: 0x24637e90  addiu       $v1, $v1, 0x7E90
    ctx->pc = 0x1b92bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32400));
    // 0x1b92c0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b92c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b92c4: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1b92c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b92c8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b92c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b92cc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b92ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b92d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b92d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b92d4: 0x90420006  lbu         $v0, 0x6($v0)
    ctx->pc = 0x1b92d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x1b92d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B92D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B92DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B92D8u;
            // 0x1b92dc: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9240u: goto label_1b9240;
            case 0x1B9254u: goto label_1b9254;
            case 0x1B9264u: goto label_1b9264;
            case 0x1B9270u: goto label_1b9270;
            case 0x1B9274u: goto label_1b9274;
            case 0x1B9290u: goto label_1b9290;
            case 0x1B9330u: goto label_1b9330;
            case 0x1B934Cu: goto label_1b934c;
            case 0x1B937Cu: goto label_1b937c;
            case 0x1B9384u: goto label_1b9384;
            case 0x1B939Cu: goto label_1b939c;
            case 0x1B93A0u: goto label_1b93a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B92E0u;
    // 0x1b92e0: 0x94820bba  lhu         $v0, 0xBBA($a0)
    ctx->pc = 0x1b92e0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 3002)));
    // 0x1b92e4: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1b92e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1b92e8: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x1b92e8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1b92ec: 0x24637e90  addiu       $v1, $v1, 0x7E90
    ctx->pc = 0x1b92ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32400));
    // 0x1b92f0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b92f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b92f4: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x1b92f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1b92f8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b92f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b92fc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b92fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9300: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9304: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9304u;
            // 0x1b9308: 0x80420007  lb          $v0, 0x7($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 7)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9240u: goto label_1b9240;
            case 0x1B9254u: goto label_1b9254;
            case 0x1B9264u: goto label_1b9264;
            case 0x1B9270u: goto label_1b9270;
            case 0x1B9274u: goto label_1b9274;
            case 0x1B9290u: goto label_1b9290;
            case 0x1B9330u: goto label_1b9330;
            case 0x1B934Cu: goto label_1b934c;
            case 0x1B937Cu: goto label_1b937c;
            case 0x1B9384u: goto label_1b9384;
            case 0x1B939Cu: goto label_1b939c;
            case 0x1B93A0u: goto label_1b93a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B930Cu;
    // 0x1b930c: 0x0  nop
    ctx->pc = 0x1b930cu;
    // NOP
    // 0x1b9310: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b9310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b9314: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b9314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b9318: 0x90860554  lbu         $a2, 0x554($a0)
    ctx->pc = 0x1b9318u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1364)));
    // 0x1b931c: 0x14c00004  bnez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B931Cu;
    {
        const bool branch_taken_0x1b931c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b931c) {
            ctx->pc = 0x1B9330u;
            goto label_1b9330;
        }
    }
    ctx->pc = 0x1B9324u;
    // 0x1b9324: 0x90830033  lbu         $v1, 0x33($a0)
    ctx->pc = 0x1b9324u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 51)));
    // 0x1b9328: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B9328u;
    {
        const bool branch_taken_0x1b9328 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9328) {
            ctx->pc = 0x1B934Cu;
            goto label_1b934c;
        }
    }
    ctx->pc = 0x1B9330u;
label_1b9330:
    // 0x1b9330: 0x908a0033  lbu         $t2, 0x33($a0)
    ctx->pc = 0x1b9330u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 51)));
    // 0x1b9334: 0x24870038  addiu       $a3, $a0, 0x38
    ctx->pc = 0x1b9334u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x1b9338: 0x30c600ff  andi        $a2, $a2, 0xFF
    ctx->pc = 0x1b9338u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1b933c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b933cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9340: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9340u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9344: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9344u;
    SET_GPR_U32(ctx, 31, 0x1B934Cu);
    ctx->pc = 0x1B9348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9344u;
            // 0x1b9348: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B934Cu; }
        if (ctx->pc != 0x1B934Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B934Cu; }
        if (ctx->pc != 0x1B934Cu) { return; }
    }
    ctx->pc = 0x1B934Cu;
label_1b934c:
    // 0x1b934c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b934cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9350: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9350u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9350u;
            // 0x1b9354: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9240u: goto label_1b9240;
            case 0x1B9254u: goto label_1b9254;
            case 0x1B9264u: goto label_1b9264;
            case 0x1B9270u: goto label_1b9270;
            case 0x1B9274u: goto label_1b9274;
            case 0x1B9290u: goto label_1b9290;
            case 0x1B9330u: goto label_1b9330;
            case 0x1B934Cu: goto label_1b934c;
            case 0x1B937Cu: goto label_1b937c;
            case 0x1B9384u: goto label_1b9384;
            case 0x1B939Cu: goto label_1b939c;
            case 0x1B93A0u: goto label_1b93a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9358u;
    // 0x1b9358: 0x0  nop
    ctx->pc = 0x1b9358u;
    // NOP
    // 0x1b935c: 0x0  nop
    ctx->pc = 0x1b935cu;
    // NOP
    // 0x1b9360: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b9360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b9364: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1b9364u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9368: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B9368u;
    {
        const bool branch_taken_0x1b9368 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B936Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9368u;
            // 0x1b936c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9368) {
            ctx->pc = 0x1B9384u;
            goto label_1b9384;
        }
    }
    ctx->pc = 0x1B9370u;
    // 0x1b9370: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9374: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B9374u;
    SET_GPR_U32(ctx, 31, 0x1B937Cu);
    ctx->pc = 0x1B9378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9374u;
            // 0x1b9378: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B937Cu; }
        if (ctx->pc != 0x1B937Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B937Cu; }
        if (ctx->pc != 0x1B937Cu) { return; }
    }
    ctx->pc = 0x1B937Cu;
label_1b937c:
    // 0x1b937c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B937Cu;
    {
        const bool branch_taken_0x1b937c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B937Cu;
            // 0x1b9380: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b937c) {
            ctx->pc = 0x1B93A0u;
            goto label_1b93a0;
        }
    }
    ctx->pc = 0x1B9384u;
label_1b9384:
    // 0x1b9384: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9388: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9388u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b938c: 0x24080002  addiu       $t0, $zero, 0x2
    ctx->pc = 0x1b938cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9390: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9390u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9394: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9394u;
    SET_GPR_U32(ctx, 31, 0x1B939Cu);
    ctx->pc = 0x1B9398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9394u;
            // 0x1b9398: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B939Cu; }
        if (ctx->pc != 0x1B939Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B939Cu; }
        if (ctx->pc != 0x1B939Cu) { return; }
    }
    ctx->pc = 0x1B939Cu;
label_1b939c:
    // 0x1b939c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b939cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b93a0:
    // 0x1b93a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B93A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B93A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B93A0u;
            // 0x1b93a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9240u: goto label_1b9240;
            case 0x1B9254u: goto label_1b9254;
            case 0x1B9264u: goto label_1b9264;
            case 0x1B9270u: goto label_1b9270;
            case 0x1B9274u: goto label_1b9274;
            case 0x1B9290u: goto label_1b9290;
            case 0x1B9330u: goto label_1b9330;
            case 0x1B934Cu: goto label_1b934c;
            case 0x1B937Cu: goto label_1b937c;
            case 0x1B9384u: goto label_1b9384;
            case 0x1B939Cu: goto label_1b939c;
            case 0x1B93A0u: goto label_1b93a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B93A8u;
    // 0x1b93a8: 0x0  nop
    ctx->pc = 0x1b93a8u;
    // NOP
    // 0x1b93ac: 0x0  nop
    ctx->pc = 0x1b93acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
