#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB180
// Address: 0x1cb180 - 0x1cb7b0
void sub_001CB180_0x1cb180(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB180_0x1cb180");
#endif

    switch (ctx->pc) {
        case 0x1cb1b0u: goto label_1cb1b0;
        case 0x1cb250u: goto label_1cb250;
        case 0x1cb270u: goto label_1cb270;
        case 0x1cb2b4u: goto label_1cb2b4;
        case 0x1cb2c8u: goto label_1cb2c8;
        case 0x1cb310u: goto label_1cb310;
        case 0x1cb344u: goto label_1cb344;
        case 0x1cb398u: goto label_1cb398;
        case 0x1cb3a0u: goto label_1cb3a0;
        case 0x1cb3bcu: goto label_1cb3bc;
        case 0x1cb3c4u: goto label_1cb3c4;
        case 0x1cb3dcu: goto label_1cb3dc;
        case 0x1cb3f0u: goto label_1cb3f0;
        case 0x1cb428u: goto label_1cb428;
        case 0x1cb438u: goto label_1cb438;
        case 0x1cb46cu: goto label_1cb46c;
        case 0x1cb4acu: goto label_1cb4ac;
        case 0x1cb508u: goto label_1cb508;
        case 0x1cb558u: goto label_1cb558;
        case 0x1cb578u: goto label_1cb578;
        case 0x1cb5f0u: goto label_1cb5f0;
        case 0x1cb684u: goto label_1cb684;
        case 0x1cb6c0u: goto label_1cb6c0;
        case 0x1cb6d0u: goto label_1cb6d0;
        case 0x1cb710u: goto label_1cb710;
        default: break;
    }

    ctx->pc = 0x1cb180u;

    // 0x1cb180: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cb180u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cb184: 0x3c070025  lui         $a3, 0x25
    ctx->pc = 0x1cb184u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)37 << 16));
    // 0x1cb188: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cb188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cb18c: 0x24e72e60  addiu       $a3, $a3, 0x2E60
    ctx->pc = 0x1cb18cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 11872));
    // 0x1cb190: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cb190u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cb194: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cb194u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cb198: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1cb198u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb19c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1cb19cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb1a0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1cb1a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb1a4: 0x2405001a  addiu       $a1, $zero, 0x1A
    ctx->pc = 0x1cb1a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x1cb1a8: 0xc072420  jal         func_1C9080
    ctx->pc = 0x1CB1A8u;
    SET_GPR_U32(ctx, 31, 0x1CB1B0u);
    ctx->pc = 0x1CB1ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB1A8u;
            // 0x1cb1ac: 0x80302d  daddu       $a2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C9080u;
    if (runtime->hasFunction(0x1C9080u)) {
        auto targetFn = runtime->lookupFunction(0x1C9080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB1B0u; }
        if (ctx->pc != 0x1CB1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9080_0x1c9080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB1B0u; }
        if (ctx->pc != 0x1CB1B0u) { return; }
    }
    ctx->pc = 0x1CB1B0u;
label_1cb1b0:
    // 0x1cb1b0: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1cb1b0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb1b4: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x1cb1b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1cb1b8: 0x10640168  beq         $v1, $a0, . + 4 + (0x168 << 2)
    ctx->pc = 0x1CB1B8u;
    {
        const bool branch_taken_0x1cb1b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1cb1b8) {
            ctx->pc = 0x1CB75Cu;
            goto label_1cb75c;
        }
    }
    ctx->pc = 0x1CB1C0u;
    // 0x1cb1c0: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1cb1c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1cb1c4: 0x10620159  beq         $v1, $v0, . + 4 + (0x159 << 2)
    ctx->pc = 0x1CB1C4u;
    {
        const bool branch_taken_0x1cb1c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb1c4) {
            ctx->pc = 0x1CB72Cu;
            goto label_1cb72c;
        }
    }
    ctx->pc = 0x1CB1CCu;
    // 0x1cb1cc: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1cb1ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1cb1d0: 0x10620146  beq         $v1, $v0, . + 4 + (0x146 << 2)
    ctx->pc = 0x1CB1D0u;
    {
        const bool branch_taken_0x1cb1d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb1d0) {
            ctx->pc = 0x1CB6ECu;
            goto label_1cb6ec;
        }
    }
    ctx->pc = 0x1CB1D8u;
    // 0x1cb1d8: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1cb1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1cb1dc: 0x10620111  beq         $v1, $v0, . + 4 + (0x111 << 2)
    ctx->pc = 0x1CB1DCu;
    {
        const bool branch_taken_0x1cb1dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb1dc) {
            ctx->pc = 0x1CB624u;
            goto label_1cb624;
        }
    }
    ctx->pc = 0x1CB1E4u;
    // 0x1cb1e4: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1cb1e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1cb1e8: 0x106200eb  beq         $v1, $v0, . + 4 + (0xEB << 2)
    ctx->pc = 0x1CB1E8u;
    {
        const bool branch_taken_0x1cb1e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb1e8) {
            ctx->pc = 0x1CB598u;
            goto label_1cb598;
        }
    }
    ctx->pc = 0x1CB1F0u;
    // 0x1cb1f0: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1cb1f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1cb1f4: 0x106200b3  beq         $v1, $v0, . + 4 + (0xB3 << 2)
    ctx->pc = 0x1CB1F4u;
    {
        const bool branch_taken_0x1cb1f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb1f4) {
            ctx->pc = 0x1CB4C4u;
            goto label_1cb4c4;
        }
    }
    ctx->pc = 0x1CB1FCu;
    // 0x1cb1fc: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1cb1fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1cb200: 0x10650098  beq         $v1, $a1, . + 4 + (0x98 << 2)
    ctx->pc = 0x1CB200u;
    {
        const bool branch_taken_0x1cb200 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1cb200) {
            ctx->pc = 0x1CB464u;
            goto label_1cb464;
        }
    }
    ctx->pc = 0x1CB208u;
    // 0x1cb208: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1cb208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cb20c: 0x1062007d  beq         $v1, $v0, . + 4 + (0x7D << 2)
    ctx->pc = 0x1CB20Cu;
    {
        const bool branch_taken_0x1cb20c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb20c) {
            ctx->pc = 0x1CB404u;
            goto label_1cb404;
        }
    }
    ctx->pc = 0x1CB214u;
    // 0x1cb214: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1cb214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1cb218: 0x10620048  beq         $v1, $v0, . + 4 + (0x48 << 2)
    ctx->pc = 0x1CB218u;
    {
        const bool branch_taken_0x1cb218 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb218) {
            ctx->pc = 0x1CB33Cu;
            goto label_1cb33c;
        }
    }
    ctx->pc = 0x1CB220u;
    // 0x1cb220: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb224: 0x10620031  beq         $v1, $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x1CB224u;
    {
        const bool branch_taken_0x1cb224 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb224) {
            ctx->pc = 0x1CB2ECu;
            goto label_1cb2ec;
        }
    }
    ctx->pc = 0x1CB22Cu;
    // 0x1cb22c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb22cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb230: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1CB230u;
    {
        const bool branch_taken_0x1cb230 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb230) {
            ctx->pc = 0x1CB2A8u;
            goto label_1cb2a8;
        }
    }
    ctx->pc = 0x1CB238u;
    // 0x1cb238: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB238u;
    {
        const bool branch_taken_0x1cb238 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb238) {
            ctx->pc = 0x1CB248u;
            goto label_1cb248;
        }
    }
    ctx->pc = 0x1CB240u;
    // 0x1cb240: 0x10000153  b           . + 4 + (0x153 << 2)
    ctx->pc = 0x1CB240u;
    {
        const bool branch_taken_0x1cb240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB240u;
            // 0x1cb244: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb240) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB248u;
label_1cb248:
    // 0x1cb248: 0xc0759c4  jal         func_1D6710
    ctx->pc = 0x1CB248u;
    SET_GPR_U32(ctx, 31, 0x1CB250u);
    ctx->pc = 0x1D6710u;
    if (runtime->hasFunction(0x1D6710u)) {
        auto targetFn = runtime->lookupFunction(0x1D6710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB250u; }
        if (ctx->pc != 0x1CB250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6710_0x1d6710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB250u; }
        if (ctx->pc != 0x1CB250u) { return; }
    }
    ctx->pc = 0x1CB250u;
label_1cb250:
    // 0x1cb250: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CB250u;
    {
        const bool branch_taken_0x1cb250 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cb250) {
            ctx->pc = 0x1CB268u;
            goto label_1cb268;
        }
    }
    ctx->pc = 0x1CB258u;
    // 0x1cb258: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1cb258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1cb25c: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb25cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb260: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1CB260u;
    {
        const bool branch_taken_0x1cb260 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB260u;
            // 0x1cb264: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb260) {
            ctx->pc = 0x1CB2A0u;
            goto label_1cb2a0;
        }
    }
    ctx->pc = 0x1CB268u;
label_1cb268:
    // 0x1cb268: 0xc0759c4  jal         func_1D6710
    ctx->pc = 0x1CB268u;
    SET_GPR_U32(ctx, 31, 0x1CB270u);
    ctx->pc = 0x1D6710u;
    if (runtime->hasFunction(0x1D6710u)) {
        auto targetFn = runtime->lookupFunction(0x1D6710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB270u; }
        if (ctx->pc != 0x1CB270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6710_0x1d6710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB270u; }
        if (ctx->pc != 0x1CB270u) { return; }
    }
    ctx->pc = 0x1CB270u;
label_1cb270:
    // 0x1cb270: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1cb270u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1cb274: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB274u;
    {
        const bool branch_taken_0x1cb274 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1cb274) {
            ctx->pc = 0x1CB294u;
            goto label_1cb294;
        }
    }
    ctx->pc = 0x1CB27Cu;
    // 0x1cb27c: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1cb27cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb280: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb280u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb284: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cb284u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cb288: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1cb288u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb28c: 0x10000140  b           . + 4 + (0x140 << 2)
    ctx->pc = 0x1CB28Cu;
    {
        const bool branch_taken_0x1cb28c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB28Cu;
            // 0x1cb290: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb28c) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB294u;
label_1cb294:
    // 0x1cb294: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb294u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb298: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb298u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb29c: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb29cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1cb2a0:
    // 0x1cb2a0: 0x1000013b  b           . + 4 + (0x13B << 2)
    ctx->pc = 0x1CB2A0u;
    {
        const bool branch_taken_0x1cb2a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB2A0u;
            // 0x1cb2a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb2a0) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB2A8u;
label_1cb2a8:
    // 0x1cb2a8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cb2a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cb2ac: 0xc075abc  jal         func_1D6AF0
    ctx->pc = 0x1CB2ACu;
    SET_GPR_U32(ctx, 31, 0x1CB2B4u);
    ctx->pc = 0x1CB2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB2ACu;
            // 0x1cb2b0: 0x2484b694  addiu       $a0, $a0, -0x496C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948500));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6AF0u;
    if (runtime->hasFunction(0x1D6AF0u)) {
        auto targetFn = runtime->lookupFunction(0x1D6AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB2B4u; }
        if (ctx->pc != 0x1CB2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6AF0_0x1d6af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB2B4u; }
        if (ctx->pc != 0x1CB2B4u) { return; }
    }
    ctx->pc = 0x1CB2B4u;
label_1cb2b4:
    // 0x1cb2b4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cb2b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cb2b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cb2b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb2bc: 0x2484b690  addiu       $a0, $a0, -0x4970
    ctx->pc = 0x1cb2bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948496));
    // 0x1cb2c0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CB2C0u;
    SET_GPR_U32(ctx, 31, 0x1CB2C8u);
    ctx->pc = 0x1CB2C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB2C0u;
            // 0x1cb2c4: 0x2406002c  addiu       $a2, $zero, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB2C8u; }
        if (ctx->pc != 0x1CB2C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB2C8u; }
        if (ctx->pc != 0x1CB2C8u) { return; }
    }
    ctx->pc = 0x1CB2C8u;
label_1cb2c8:
    // 0x1cb2c8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb2c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb2cc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb2ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb2d0: 0xac23b694  sw          $v1, -0x496C($at)
    ctx->pc = 0x1cb2d0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294948500), GPR_U32(ctx, 3));
    // 0x1cb2d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb2d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb2d8: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1cb2d8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb2dc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cb2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cb2e0: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1cb2e0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb2e4: 0x1000012a  b           . + 4 + (0x12A << 2)
    ctx->pc = 0x1CB2E4u;
    {
        const bool branch_taken_0x1cb2e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB2E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB2E4u;
            // 0x1cb2e8: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb2e4) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB2ECu;
label_1cb2ec:
    // 0x1cb2ec: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1cb2ecu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb2f0: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1cb2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cb2f4: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1cb2f4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb2f8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB2F8u;
    {
        const bool branch_taken_0x1cb2f8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB2FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB2F8u;
            // 0x1cb2fc: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb2f8) {
            ctx->pc = 0x1CB308u;
            goto label_1cb308;
        }
    }
    ctx->pc = 0x1CB300u;
    // 0x1cb300: 0x10000123  b           . + 4 + (0x123 << 2)
    ctx->pc = 0x1CB300u;
    {
        const bool branch_taken_0x1cb300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB300u;
            // 0x1cb304: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb300) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB308u;
label_1cb308:
    // 0x1cb308: 0xc0759c4  jal         func_1D6710
    ctx->pc = 0x1CB308u;
    SET_GPR_U32(ctx, 31, 0x1CB310u);
    ctx->pc = 0x1CB30Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB308u;
            // 0x1cb30c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6710u;
    if (runtime->hasFunction(0x1D6710u)) {
        auto targetFn = runtime->lookupFunction(0x1D6710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB310u; }
        if (ctx->pc != 0x1CB310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6710_0x1d6710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB310u; }
        if (ctx->pc != 0x1CB310u) { return; }
    }
    ctx->pc = 0x1CB310u;
label_1cb310:
    // 0x1cb310: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cb310u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb314: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CB314u;
    {
        const bool branch_taken_0x1cb314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1cb314) {
            ctx->pc = 0x1CB328u;
            goto label_1cb328;
        }
    }
    ctx->pc = 0x1CB31Cu;
    // 0x1cb31c: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1cb31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1cb320: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1CB320u;
    {
        const bool branch_taken_0x1cb320 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB320u;
            // 0x1cb324: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb320) {
            ctx->pc = 0x1CB334u;
            goto label_1cb334;
        }
    }
    ctx->pc = 0x1CB328u;
label_1cb328:
    // 0x1cb328: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb328u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb32c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb32cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb330: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb330u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
label_1cb334:
    // 0x1cb334: 0x10000116  b           . + 4 + (0x116 << 2)
    ctx->pc = 0x1CB334u;
    {
        const bool branch_taken_0x1cb334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB334u;
            // 0x1cb338: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb334) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB33Cu;
label_1cb33c:
    // 0x1cb33c: 0xc075b1c  jal         func_1D6C70
    ctx->pc = 0x1CB33Cu;
    SET_GPR_U32(ctx, 31, 0x1CB344u);
    ctx->pc = 0x1D6C70u;
    if (runtime->hasFunction(0x1D6C70u)) {
        auto targetFn = runtime->lookupFunction(0x1D6C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB344u; }
        if (ctx->pc != 0x1CB344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6C70_0x1d6c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB344u; }
        if (ctx->pc != 0x1CB344u) { return; }
    }
    ctx->pc = 0x1CB344u;
label_1cb344:
    // 0x1cb344: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb344u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb348: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1cb348u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb34c: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1cb34cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1cb350: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1cb350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cb354: 0x14440024  bne         $v0, $a0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1CB354u;
    {
        const bool branch_taken_0x1cb354 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cb354) {
            ctx->pc = 0x1CB3E8u;
            goto label_1cb3e8;
        }
    }
    ctx->pc = 0x1CB35Cu;
    // 0x1cb35c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb35cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb360: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb360u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb364: 0x8023cc48  lb          $v1, -0x33B8($at)
    ctx->pc = 0x1cb364u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1cb368: 0x1062001a  beq         $v1, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1CB368u;
    {
        const bool branch_taken_0x1cb368 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb368) {
            ctx->pc = 0x1CB3D4u;
            goto label_1cb3d4;
        }
    }
    ctx->pc = 0x1CB370u;
    // 0x1cb370: 0x1064000e  beq         $v1, $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CB370u;
    {
        const bool branch_taken_0x1cb370 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1cb370) {
            ctx->pc = 0x1CB3ACu;
            goto label_1cb3ac;
        }
    }
    ctx->pc = 0x1CB378u;
    // 0x1cb378: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB378u;
    {
        const bool branch_taken_0x1cb378 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb378) {
            ctx->pc = 0x1CB388u;
            goto label_1cb388;
        }
    }
    ctx->pc = 0x1CB380u;
    // 0x1cb380: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1CB380u;
    {
        const bool branch_taken_0x1cb380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB380u;
            // 0x1cb384: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb380) {
            ctx->pc = 0x1CB3FCu;
            goto label_1cb3fc;
        }
    }
    ctx->pc = 0x1CB388u;
label_1cb388:
    // 0x1cb388: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb388u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb38c: 0x8c25c800  lw          $a1, -0x3800($at)
    ctx->pc = 0x1cb38cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952960)));
    // 0x1cb390: 0xc075d40  jal         func_1D7500
    ctx->pc = 0x1CB390u;
    SET_GPR_U32(ctx, 31, 0x1CB398u);
    ctx->pc = 0x1CB394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB390u;
            // 0x1cb394: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7500u;
    if (runtime->hasFunction(0x1D7500u)) {
        auto targetFn = runtime->lookupFunction(0x1D7500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB398u; }
        if (ctx->pc != 0x1CB398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7500_0x1d7500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB398u; }
        if (ctx->pc != 0x1CB398u) { return; }
    }
    ctx->pc = 0x1CB398u;
label_1cb398:
    // 0x1cb398: 0xc075cf0  jal         func_1D73C0
    ctx->pc = 0x1CB398u;
    SET_GPR_U32(ctx, 31, 0x1CB3A0u);
    ctx->pc = 0x1CB39Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB398u;
            // 0x1cb39c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D73C0u;
    if (runtime->hasFunction(0x1D73C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D73C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3A0u; }
        if (ctx->pc != 0x1CB3A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D73C0_0x1d73c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3A0u; }
        if (ctx->pc != 0x1CB3A0u) { return; }
    }
    ctx->pc = 0x1CB3A0u;
label_1cb3a0:
    // 0x1cb3a0: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1cb3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1cb3a4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1CB3A4u;
    {
        const bool branch_taken_0x1cb3a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB3A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3A4u;
            // 0x1cb3a8: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb3a4) {
            ctx->pc = 0x1CB3F8u;
            goto label_1cb3f8;
        }
    }
    ctx->pc = 0x1CB3ACu;
label_1cb3ac:
    // 0x1cb3ac: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb3acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb3b0: 0x8c25c800  lw          $a1, -0x3800($at)
    ctx->pc = 0x1cb3b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952960)));
    // 0x1cb3b4: 0xc075d40  jal         func_1D7500
    ctx->pc = 0x1CB3B4u;
    SET_GPR_U32(ctx, 31, 0x1CB3BCu);
    ctx->pc = 0x1CB3B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3B4u;
            // 0x1cb3b8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7500u;
    if (runtime->hasFunction(0x1D7500u)) {
        auto targetFn = runtime->lookupFunction(0x1D7500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3BCu; }
        if (ctx->pc != 0x1CB3BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7500_0x1d7500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3BCu; }
        if (ctx->pc != 0x1CB3BCu) { return; }
    }
    ctx->pc = 0x1CB3BCu;
label_1cb3bc:
    // 0x1cb3bc: 0xc075cf0  jal         func_1D73C0
    ctx->pc = 0x1CB3BCu;
    SET_GPR_U32(ctx, 31, 0x1CB3C4u);
    ctx->pc = 0x1CB3C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3BCu;
            // 0x1cb3c0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D73C0u;
    if (runtime->hasFunction(0x1D73C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D73C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3C4u; }
        if (ctx->pc != 0x1CB3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D73C0_0x1d73c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3C4u; }
        if (ctx->pc != 0x1CB3C4u) { return; }
    }
    ctx->pc = 0x1CB3C4u;
label_1cb3c4:
    // 0x1cb3c4: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb3c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb3c8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb3cc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CB3CCu;
    {
        const bool branch_taken_0x1cb3cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB3D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3CCu;
            // 0x1cb3d0: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb3cc) {
            ctx->pc = 0x1CB3F8u;
            goto label_1cb3f8;
        }
    }
    ctx->pc = 0x1CB3D4u;
label_1cb3d4:
    // 0x1cb3d4: 0xc075c0c  jal         func_1D7030
    ctx->pc = 0x1CB3D4u;
    SET_GPR_U32(ctx, 31, 0x1CB3DCu);
    ctx->pc = 0x1CB3D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3D4u;
            // 0x1cb3d8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7030u;
    if (runtime->hasFunction(0x1D7030u)) {
        auto targetFn = runtime->lookupFunction(0x1D7030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3DCu; }
        if (ctx->pc != 0x1CB3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7030_0x1d7030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3DCu; }
        if (ctx->pc != 0x1CB3DCu) { return; }
    }
    ctx->pc = 0x1CB3DCu;
label_1cb3dc:
    // 0x1cb3dc: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1cb3dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1cb3e0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CB3E0u;
    {
        const bool branch_taken_0x1cb3e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3E0u;
            // 0x1cb3e4: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb3e0) {
            ctx->pc = 0x1CB3F8u;
            goto label_1cb3f8;
        }
    }
    ctx->pc = 0x1CB3E8u;
label_1cb3e8:
    // 0x1cb3e8: 0xc075c0c  jal         func_1D7030
    ctx->pc = 0x1CB3E8u;
    SET_GPR_U32(ctx, 31, 0x1CB3F0u);
    ctx->pc = 0x1CB3ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3E8u;
            // 0x1cb3ec: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7030u;
    if (runtime->hasFunction(0x1D7030u)) {
        auto targetFn = runtime->lookupFunction(0x1D7030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3F0u; }
        if (ctx->pc != 0x1CB3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7030_0x1d7030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB3F0u; }
        if (ctx->pc != 0x1CB3F0u) { return; }
    }
    ctx->pc = 0x1CB3F0u;
label_1cb3f0:
    // 0x1cb3f0: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1cb3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1cb3f4: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb3f4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
label_1cb3f8:
    // 0x1cb3f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb3f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb3fc:
    // 0x1cb3fc: 0x100000e5  b           . + 4 + (0xE5 << 2)
    ctx->pc = 0x1CB3FCu;
    {
        const bool branch_taken_0x1cb3fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB3FCu;
            // 0x1cb400: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb3fc) {
            ctx->pc = 0x1CB794u;
            goto label_1cb794;
        }
    }
    ctx->pc = 0x1CB404u;
label_1cb404:
    // 0x1cb404: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb404u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb408: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cb408u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cb40c: 0xac20b664  sw          $zero, -0x499C($at)
    ctx->pc = 0x1cb40cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294948452), GPR_U32(ctx, 0));
    // 0x1cb410: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x1cb410u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x1cb414: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb414u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb418: 0x8c22c810  lw          $v0, -0x37F0($at)
    ctx->pc = 0x1cb418u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952976)));
    // 0x1cb41c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb41cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb420: 0xc075da4  jal         func_1D7690
    ctx->pc = 0x1CB420u;
    SET_GPR_U32(ctx, 31, 0x1CB428u);
    ctx->pc = 0x1CB424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB420u;
            // 0x1cb424: 0xac22b660  sw          $v0, -0x49A0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294948448), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7690u;
    if (runtime->hasFunction(0x1D7690u)) {
        auto targetFn = runtime->lookupFunction(0x1D7690u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB428u; }
        if (ctx->pc != 0x1CB428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7690_0x1d7690(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB428u; }
        if (ctx->pc != 0x1CB428u) { return; }
    }
    ctx->pc = 0x1CB428u;
label_1cb428:
    // 0x1cb428: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB428u;
    {
        const bool branch_taken_0x1cb428 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb428) {
            ctx->pc = 0x1CB448u;
            goto label_1cb448;
        }
    }
    ctx->pc = 0x1CB430u;
    // 0x1cb430: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CB430u;
    SET_GPR_U32(ctx, 31, 0x1CB438u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB438u; }
        if (ctx->pc != 0x1CB438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB438u; }
        if (ctx->pc != 0x1CB438u) { return; }
    }
    ctx->pc = 0x1CB438u;
label_1cb438:
    // 0x1cb438: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb438u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb43c: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1cb43cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1cb440: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CB440u;
    {
        const bool branch_taken_0x1cb440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB440u;
            // 0x1cb444: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb440) {
            ctx->pc = 0x1CB45Cu;
            goto label_1cb45c;
        }
    }
    ctx->pc = 0x1CB448u;
label_1cb448:
    // 0x1cb448: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1cb448u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb44c: 0x2402012c  addiu       $v0, $zero, 0x12C
    ctx->pc = 0x1cb44cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x1cb450: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cb450u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cb454: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1cb454u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb458: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1cb458u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_1cb45c:
    // 0x1cb45c: 0x100000cc  b           . + 4 + (0xCC << 2)
    ctx->pc = 0x1CB45Cu;
    {
        const bool branch_taken_0x1cb45c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB45Cu;
            // 0x1cb460: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb45c) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB464u;
label_1cb464:
    // 0x1cb464: 0xc075d74  jal         func_1D75D0
    ctx->pc = 0x1CB464u;
    SET_GPR_U32(ctx, 31, 0x1CB46Cu);
    ctx->pc = 0x1D75D0u;
    if (runtime->hasFunction(0x1D75D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D75D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB46Cu; }
        if (ctx->pc != 0x1CB46Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D75D0_0x1d75d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB46Cu; }
        if (ctx->pc != 0x1CB46Cu) { return; }
    }
    ctx->pc = 0x1CB46Cu;
label_1cb46c:
    // 0x1cb46c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb46cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb470: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1CB470u;
    {
        const bool branch_taken_0x1cb470 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cb470) {
            ctx->pc = 0x1CB4A4u;
            goto label_1cb4a4;
        }
    }
    ctx->pc = 0x1CB478u;
    // 0x1cb478: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x1cb478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1cb47c: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CB47Cu;
    {
        const bool branch_taken_0x1cb47c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cb47c) {
            ctx->pc = 0x1CB4A4u;
            goto label_1cb4a4;
        }
    }
    ctx->pc = 0x1CB484u;
    // 0x1cb484: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB484u;
    {
        const bool branch_taken_0x1cb484 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb484) {
            ctx->pc = 0x1CB4A4u;
            goto label_1cb4a4;
        }
    }
    ctx->pc = 0x1CB48Cu;
    // 0x1cb48c: 0x86020000  lh          $v0, 0x0($s0)
    ctx->pc = 0x1cb48cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb490: 0x2443ffff  addiu       $v1, $v0, -0x1
    ctx->pc = 0x1cb490u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1cb494: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x1cb494u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1cb498: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CB498u;
    {
        const bool branch_taken_0x1cb498 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CB49Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB498u;
            // 0x1cb49c: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb498) {
            ctx->pc = 0x1CB4BCu;
            goto label_1cb4bc;
        }
    }
    ctx->pc = 0x1CB4A0u;
    // 0x1cb4a0: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb4a0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1cb4a4:
    // 0x1cb4a4: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CB4A4u;
    SET_GPR_U32(ctx, 31, 0x1CB4ACu);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB4ACu; }
        if (ctx->pc != 0x1CB4ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB4ACu; }
        if (ctx->pc != 0x1CB4ACu) { return; }
    }
    ctx->pc = 0x1CB4ACu;
label_1cb4ac:
    // 0x1cb4ac: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb4acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb4b0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb4b4: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb4b4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb4b8: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb4b8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1cb4bc:
    // 0x1cb4bc: 0x100000b4  b           . + 4 + (0xB4 << 2)
    ctx->pc = 0x1CB4BCu;
    {
        const bool branch_taken_0x1cb4bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB4C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB4BCu;
            // 0x1cb4c0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb4bc) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB4C4u;
label_1cb4c4:
    // 0x1cb4c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb4c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb4c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb4c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb4cc: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1cb4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1cb4d0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1cb4d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cb4d4: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CB4D4u;
    {
        const bool branch_taken_0x1cb4d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb4d4) {
            ctx->pc = 0x1CB520u;
            goto label_1cb520;
        }
    }
    ctx->pc = 0x1CB4DCu;
    // 0x1cb4dc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1cb4dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1cb4e0: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB4E0u;
    {
        const bool branch_taken_0x1cb4e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CB4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB4E0u;
            // 0x1cb4e4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb4e0) {
            ctx->pc = 0x1CB500u;
            goto label_1cb500;
        }
    }
    ctx->pc = 0x1CB4E8u;
    // 0x1cb4e8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb4ec: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB4ECu;
    {
        const bool branch_taken_0x1cb4ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb4ec) {
            ctx->pc = 0x1CB4FCu;
            goto label_1cb4fc;
        }
    }
    ctx->pc = 0x1CB4F4u;
    // 0x1cb4f4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1CB4F4u;
    {
        const bool branch_taken_0x1cb4f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB4F4u;
            // 0x1cb4f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb4f4) {
            ctx->pc = 0x1CB590u;
            goto label_1cb590;
        }
    }
    ctx->pc = 0x1CB4FCu;
label_1cb4fc:
    // 0x1cb4fc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cb4fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb500:
    // 0x1cb500: 0xc075c98  jal         func_1D7260
    ctx->pc = 0x1CB500u;
    SET_GPR_U32(ctx, 31, 0x1CB508u);
    ctx->pc = 0x1D7260u;
    if (runtime->hasFunction(0x1D7260u)) {
        auto targetFn = runtime->lookupFunction(0x1D7260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB508u; }
        if (ctx->pc != 0x1CB508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7260_0x1d7260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB508u; }
        if (ctx->pc != 0x1CB508u) { return; }
    }
    ctx->pc = 0x1CB508u;
label_1cb508:
    // 0x1cb508: 0x2402012c  addiu       $v0, $zero, 0x12C
    ctx->pc = 0x1cb508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x1cb50c: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1cb50cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cb510: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb510u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb514: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb518: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1CB518u;
    {
        const bool branch_taken_0x1cb518 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB518u;
            // 0x1cb51c: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb518) {
            ctx->pc = 0x1CB58Cu;
            goto label_1cb58c;
        }
    }
    ctx->pc = 0x1CB520u;
label_1cb520:
    // 0x1cb520: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb520u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb524: 0x8023cc48  lb          $v1, -0x33B8($at)
    ctx->pc = 0x1cb524u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1cb528: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1CB528u;
    {
        const bool branch_taken_0x1cb528 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb528) {
            ctx->pc = 0x1CB570u;
            goto label_1cb570;
        }
    }
    ctx->pc = 0x1CB530u;
    // 0x1cb530: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1CB530u;
    {
        const bool branch_taken_0x1cb530 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb530) {
            ctx->pc = 0x1CB570u;
            goto label_1cb570;
        }
    }
    ctx->pc = 0x1CB538u;
    // 0x1cb538: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb53c: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CB53Cu;
    {
        const bool branch_taken_0x1cb53c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CB540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB53Cu;
            // 0x1cb540: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb53c) {
            ctx->pc = 0x1CB550u;
            goto label_1cb550;
        }
    }
    ctx->pc = 0x1CB544u;
    // 0x1cb544: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1CB544u;
    {
        const bool branch_taken_0x1cb544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb544) {
            ctx->pc = 0x1CB58Cu;
            goto label_1cb58c;
        }
    }
    ctx->pc = 0x1CB54Cu;
    // 0x1cb54c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cb54cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb550:
    // 0x1cb550: 0xc075c98  jal         func_1D7260
    ctx->pc = 0x1CB550u;
    SET_GPR_U32(ctx, 31, 0x1CB558u);
    ctx->pc = 0x1D7260u;
    if (runtime->hasFunction(0x1D7260u)) {
        auto targetFn = runtime->lookupFunction(0x1D7260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB558u; }
        if (ctx->pc != 0x1CB558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7260_0x1d7260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB558u; }
        if (ctx->pc != 0x1CB558u) { return; }
    }
    ctx->pc = 0x1CB558u;
label_1cb558:
    // 0x1cb558: 0x2402012c  addiu       $v0, $zero, 0x12C
    ctx->pc = 0x1cb558u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x1cb55c: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1cb55cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cb560: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb560u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb564: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb568: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CB568u;
    {
        const bool branch_taken_0x1cb568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB56Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB568u;
            // 0x1cb56c: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb568) {
            ctx->pc = 0x1CB58Cu;
            goto label_1cb58c;
        }
    }
    ctx->pc = 0x1CB570u;
label_1cb570:
    // 0x1cb570: 0xc075d14  jal         func_1D7450
    ctx->pc = 0x1CB570u;
    SET_GPR_U32(ctx, 31, 0x1CB578u);
    ctx->pc = 0x1D7450u;
    if (runtime->hasFunction(0x1D7450u)) {
        auto targetFn = runtime->lookupFunction(0x1D7450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB578u; }
        if (ctx->pc != 0x1CB578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7450_0x1d7450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB578u; }
        if (ctx->pc != 0x1CB578u) { return; }
    }
    ctx->pc = 0x1CB578u;
label_1cb578:
    // 0x1cb578: 0x2402001e  addiu       $v0, $zero, 0x1E
    ctx->pc = 0x1cb578u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1cb57c: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1cb57cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cb580: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb580u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb584: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1cb584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1cb588: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb588u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
label_1cb58c:
    // 0x1cb58c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb58cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb590:
    // 0x1cb590: 0x1000007f  b           . + 4 + (0x7F << 2)
    ctx->pc = 0x1CB590u;
    {
        const bool branch_taken_0x1cb590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb590) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB598u;
label_1cb598:
    // 0x1cb598: 0x86020000  lh          $v0, 0x0($s0)
    ctx->pc = 0x1cb598u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb59c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1cb59cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1cb5a0: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1cb5a0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cb5a4: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1cb5a4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb5a8: 0x28610000  slti        $at, $v1, 0x0
    ctx->pc = 0x1cb5a8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1cb5ac: 0x10200007  beqz        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB5ACu;
    {
        const bool branch_taken_0x1cb5ac = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB5ACu;
            // 0x1cb5b0: 0x2402001e  addiu       $v0, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb5ac) {
            ctx->pc = 0x1CB5CCu;
            goto label_1cb5cc;
        }
    }
    ctx->pc = 0x1CB5B4u;
    // 0x1cb5b4: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb5b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb5b8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb5bc: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb5bcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb5c0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1CB5C0u;
    {
        const bool branch_taken_0x1cb5c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB5C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB5C0u;
            // 0x1cb5c4: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb5c0) {
            ctx->pc = 0x1CB618u;
            goto label_1cb618;
        }
    }
    ctx->pc = 0x1CB5C8u;
    // 0x1cb5c8: 0x2402001e  addiu       $v0, $zero, 0x1E
    ctx->pc = 0x1cb5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
label_1cb5cc:
    // 0x1cb5cc: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1cb5ccu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cb5d0: 0x0  nop
    ctx->pc = 0x1cb5d0u;
    // NOP
    // 0x1cb5d4: 0x0  nop
    ctx->pc = 0x1cb5d4u;
    // NOP
    // 0x1cb5d8: 0x1010  mfhi        $v0
    ctx->pc = 0x1cb5d8u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1cb5dc: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1CB5DCu;
    {
        const bool branch_taken_0x1cb5dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CB5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB5DCu;
            // 0x1cb5e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb5dc) {
            ctx->pc = 0x1CB61Cu;
            goto label_1cb61c;
        }
    }
    ctx->pc = 0x1CB5E4u;
    // 0x1cb5e4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cb5e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cb5e8: 0xc075c14  jal         func_1D7050
    ctx->pc = 0x1CB5E8u;
    SET_GPR_U32(ctx, 31, 0x1CB5F0u);
    ctx->pc = 0x1CB5ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB5E8u;
            // 0x1cb5ec: 0x2484b670  addiu       $a0, $a0, -0x4990 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7050u;
    if (runtime->hasFunction(0x1D7050u)) {
        auto targetFn = runtime->lookupFunction(0x1D7050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB5F0u; }
        if (ctx->pc != 0x1CB5F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7050_0x1d7050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB5F0u; }
        if (ctx->pc != 0x1CB5F0u) { return; }
    }
    ctx->pc = 0x1CB5F0u;
label_1cb5f0:
    // 0x1cb5f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb5f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb5f4: 0x8423b67c  lh          $v1, -0x4984($at)
    ctx->pc = 0x1cb5f4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948476)));
    // 0x1cb5f8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB5F8u;
    {
        const bool branch_taken_0x1cb5f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb5f8) {
            ctx->pc = 0x1CB608u;
            goto label_1cb608;
        }
    }
    ctx->pc = 0x1CB600u;
    // 0x1cb600: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CB600u;
    {
        const bool branch_taken_0x1cb600 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1cb600) {
            ctx->pc = 0x1CB618u;
            goto label_1cb618;
        }
    }
    ctx->pc = 0x1CB608u;
label_1cb608:
    // 0x1cb608: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1cb608u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb60c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cb60cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cb610: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1cb610u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb614: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb614u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1cb618:
    // 0x1cb618: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb618u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb61c:
    // 0x1cb61c: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x1CB61Cu;
    {
        const bool branch_taken_0x1cb61c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb61c) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB624u;
label_1cb624:
    // 0x1cb624: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1cb624u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb628: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1cb628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cb62c: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1cb62cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb630: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB630u;
    {
        const bool branch_taken_0x1cb630 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB630u;
            // 0x1cb634: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb630) {
            ctx->pc = 0x1CB640u;
            goto label_1cb640;
        }
    }
    ctx->pc = 0x1CB638u;
    // 0x1cb638: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x1CB638u;
    {
        const bool branch_taken_0x1cb638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB638u;
            // 0x1cb63c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb638) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB640u;
label_1cb640:
    // 0x1cb640: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb640u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb644: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb644u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb648: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1cb648u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1cb64c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb650: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1cb650u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cb654: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CB654u;
    {
        const bool branch_taken_0x1cb654 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb654) {
            ctx->pc = 0x1CB68Cu;
            goto label_1cb68c;
        }
    }
    ctx->pc = 0x1CB65Cu;
    // 0x1cb65c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1cb65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1cb660: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CB660u;
    {
        const bool branch_taken_0x1cb660 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb660) {
            ctx->pc = 0x1CB67Cu;
            goto label_1cb67c;
        }
    }
    ctx->pc = 0x1CB668u;
    // 0x1cb668: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb66c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB66Cu;
    {
        const bool branch_taken_0x1cb66c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb66c) {
            ctx->pc = 0x1CB67Cu;
            goto label_1cb67c;
        }
    }
    ctx->pc = 0x1CB674u;
    // 0x1cb674: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1CB674u;
    {
        const bool branch_taken_0x1cb674 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB674u;
            // 0x1cb678: 0x82240000  lb          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb674) {
            ctx->pc = 0x1CB6D4u;
            goto label_1cb6d4;
        }
    }
    ctx->pc = 0x1CB67Cu;
label_1cb67c:
    // 0x1cb67c: 0xc075ca4  jal         func_1D7290
    ctx->pc = 0x1CB67Cu;
    SET_GPR_U32(ctx, 31, 0x1CB684u);
    ctx->pc = 0x1D7290u;
    if (runtime->hasFunction(0x1D7290u)) {
        auto targetFn = runtime->lookupFunction(0x1D7290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB684u; }
        if (ctx->pc != 0x1CB684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7290_0x1d7290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB684u; }
        if (ctx->pc != 0x1CB684u) { return; }
    }
    ctx->pc = 0x1CB684u;
label_1cb684:
    // 0x1cb684: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1CB684u;
    {
        const bool branch_taken_0x1cb684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb684) {
            ctx->pc = 0x1CB6D0u;
            goto label_1cb6d0;
        }
    }
    ctx->pc = 0x1CB68Cu;
label_1cb68c:
    // 0x1cb68c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb68cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb690: 0x8023cc48  lb          $v1, -0x33B8($at)
    ctx->pc = 0x1cb690u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1cb694: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1CB694u;
    {
        const bool branch_taken_0x1cb694 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb694) {
            ctx->pc = 0x1CB6C8u;
            goto label_1cb6c8;
        }
    }
    ctx->pc = 0x1CB69Cu;
    // 0x1cb69c: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CB69Cu;
    {
        const bool branch_taken_0x1cb69c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb69c) {
            ctx->pc = 0x1CB6C8u;
            goto label_1cb6c8;
        }
    }
    ctx->pc = 0x1CB6A4u;
    // 0x1cb6a4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cb6a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cb6a8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB6A8u;
    {
        const bool branch_taken_0x1cb6a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1cb6a8) {
            ctx->pc = 0x1CB6B8u;
            goto label_1cb6b8;
        }
    }
    ctx->pc = 0x1CB6B0u;
    // 0x1cb6b0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB6B0u;
    {
        const bool branch_taken_0x1cb6b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb6b0) {
            ctx->pc = 0x1CB6D0u;
            goto label_1cb6d0;
        }
    }
    ctx->pc = 0x1CB6B8u;
label_1cb6b8:
    // 0x1cb6b8: 0xc075ca4  jal         func_1D7290
    ctx->pc = 0x1CB6B8u;
    SET_GPR_U32(ctx, 31, 0x1CB6C0u);
    ctx->pc = 0x1D7290u;
    if (runtime->hasFunction(0x1D7290u)) {
        auto targetFn = runtime->lookupFunction(0x1D7290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB6C0u; }
        if (ctx->pc != 0x1CB6C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7290_0x1d7290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB6C0u; }
        if (ctx->pc != 0x1CB6C0u) { return; }
    }
    ctx->pc = 0x1CB6C0u;
label_1cb6c0:
    // 0x1cb6c0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB6C0u;
    {
        const bool branch_taken_0x1cb6c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb6c0) {
            ctx->pc = 0x1CB6D0u;
            goto label_1cb6d0;
        }
    }
    ctx->pc = 0x1CB6C8u;
label_1cb6c8:
    // 0x1cb6c8: 0xc075d20  jal         func_1D7480
    ctx->pc = 0x1CB6C8u;
    SET_GPR_U32(ctx, 31, 0x1CB6D0u);
    ctx->pc = 0x1D7480u;
    if (runtime->hasFunction(0x1D7480u)) {
        auto targetFn = runtime->lookupFunction(0x1D7480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB6D0u; }
        if (ctx->pc != 0x1CB6D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7480_0x1d7480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB6D0u; }
        if (ctx->pc != 0x1CB6D0u) { return; }
    }
    ctx->pc = 0x1CB6D0u;
label_1cb6d0:
    // 0x1cb6d0: 0x82240000  lb          $a0, 0x0($s1)
    ctx->pc = 0x1cb6d0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_1cb6d4:
    // 0x1cb6d4: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x1cb6d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1cb6d8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb6d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb6dc: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1cb6dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1cb6e0: 0xa2240000  sb          $a0, 0x0($s1)
    ctx->pc = 0x1cb6e0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1cb6e4: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1CB6E4u;
    {
        const bool branch_taken_0x1cb6e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB6E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB6E4u;
            // 0x1cb6e8: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb6e4) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB6ECu;
label_1cb6ec:
    // 0x1cb6ec: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1cb6ecu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb6f0: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1cb6f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cb6f4: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1cb6f4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb6f8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB6F8u;
    {
        const bool branch_taken_0x1cb6f8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB6FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB6F8u;
            // 0x1cb6fc: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb6f8) {
            ctx->pc = 0x1CB708u;
            goto label_1cb708;
        }
    }
    ctx->pc = 0x1CB700u;
    // 0x1cb700: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1CB700u;
    {
        const bool branch_taken_0x1cb700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB700u;
            // 0x1cb704: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb700) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB708u;
label_1cb708:
    // 0x1cb708: 0xc075af8  jal         func_1D6BE0
    ctx->pc = 0x1CB708u;
    SET_GPR_U32(ctx, 31, 0x1CB710u);
    ctx->pc = 0x1CB70Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB708u;
            // 0x1cb70c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6BE0u;
    if (runtime->hasFunction(0x1D6BE0u)) {
        auto targetFn = runtime->lookupFunction(0x1D6BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB710u; }
        if (ctx->pc != 0x1CB710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6BE0_0x1d6be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB710u; }
        if (ctx->pc != 0x1CB710u) { return; }
    }
    ctx->pc = 0x1CB710u;
label_1cb710:
    // 0x1cb710: 0x82240000  lb          $a0, 0x0($s1)
    ctx->pc = 0x1cb710u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cb714: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x1cb714u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1cb718: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb718u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb71c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1cb71cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1cb720: 0xa2240000  sb          $a0, 0x0($s1)
    ctx->pc = 0x1cb720u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1cb724: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1CB724u;
    {
        const bool branch_taken_0x1cb724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB724u;
            // 0x1cb728: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb724) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB72Cu;
label_1cb72c:
    // 0x1cb72c: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1cb72cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb730: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1cb730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cb734: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1cb734u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb738: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB738u;
    {
        const bool branch_taken_0x1cb738 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB73Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB738u;
            // 0x1cb73c: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb738) {
            ctx->pc = 0x1CB748u;
            goto label_1cb748;
        }
    }
    ctx->pc = 0x1CB740u;
    // 0x1cb740: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CB740u;
    {
        const bool branch_taken_0x1cb740 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB740u;
            // 0x1cb744: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb740) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB748u;
label_1cb748:
    // 0x1cb748: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb748u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb74c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb74cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb750: 0xa2240000  sb          $a0, 0x0($s1)
    ctx->pc = 0x1cb750u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1cb754: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1CB754u;
    {
        const bool branch_taken_0x1cb754 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB754u;
            // 0x1cb758: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb754) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB75Cu;
label_1cb75c:
    // 0x1cb75c: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1cb75cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1cb760: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1cb760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cb764: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1cb764u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb768: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB768u;
    {
        const bool branch_taken_0x1cb768 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB76Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB768u;
            // 0x1cb76c: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb768) {
            ctx->pc = 0x1CB778u;
            goto label_1cb778;
        }
    }
    ctx->pc = 0x1CB770u;
    // 0x1cb770: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CB770u;
    {
        const bool branch_taken_0x1cb770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB770u;
            // 0x1cb774: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb770) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB778u;
label_1cb778:
    // 0x1cb778: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1cb778u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb77c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb77cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb780: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x1cb780u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb784: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB784u;
    {
        const bool branch_taken_0x1cb784 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB784u;
            // 0x1cb788: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb784) {
            ctx->pc = 0x1CB790u;
            goto label_1cb790;
        }
    }
    ctx->pc = 0x1CB78Cu;
    // 0x1cb78c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb78cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb790:
    // 0x1cb790: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cb790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1cb794:
    // 0x1cb794: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cb794u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cb798: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cb798u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb79c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB79Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB79Cu;
            // 0x1cb7a0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB1B0u: goto label_1cb1b0;
            case 0x1CB248u: goto label_1cb248;
            case 0x1CB250u: goto label_1cb250;
            case 0x1CB268u: goto label_1cb268;
            case 0x1CB270u: goto label_1cb270;
            case 0x1CB294u: goto label_1cb294;
            case 0x1CB2A0u: goto label_1cb2a0;
            case 0x1CB2A8u: goto label_1cb2a8;
            case 0x1CB2B4u: goto label_1cb2b4;
            case 0x1CB2C8u: goto label_1cb2c8;
            case 0x1CB2ECu: goto label_1cb2ec;
            case 0x1CB308u: goto label_1cb308;
            case 0x1CB310u: goto label_1cb310;
            case 0x1CB328u: goto label_1cb328;
            case 0x1CB334u: goto label_1cb334;
            case 0x1CB33Cu: goto label_1cb33c;
            case 0x1CB344u: goto label_1cb344;
            case 0x1CB388u: goto label_1cb388;
            case 0x1CB398u: goto label_1cb398;
            case 0x1CB3A0u: goto label_1cb3a0;
            case 0x1CB3ACu: goto label_1cb3ac;
            case 0x1CB3BCu: goto label_1cb3bc;
            case 0x1CB3C4u: goto label_1cb3c4;
            case 0x1CB3D4u: goto label_1cb3d4;
            case 0x1CB3DCu: goto label_1cb3dc;
            case 0x1CB3E8u: goto label_1cb3e8;
            case 0x1CB3F0u: goto label_1cb3f0;
            case 0x1CB3F8u: goto label_1cb3f8;
            case 0x1CB3FCu: goto label_1cb3fc;
            case 0x1CB404u: goto label_1cb404;
            case 0x1CB428u: goto label_1cb428;
            case 0x1CB438u: goto label_1cb438;
            case 0x1CB448u: goto label_1cb448;
            case 0x1CB45Cu: goto label_1cb45c;
            case 0x1CB464u: goto label_1cb464;
            case 0x1CB46Cu: goto label_1cb46c;
            case 0x1CB4A4u: goto label_1cb4a4;
            case 0x1CB4ACu: goto label_1cb4ac;
            case 0x1CB4BCu: goto label_1cb4bc;
            case 0x1CB4C4u: goto label_1cb4c4;
            case 0x1CB4FCu: goto label_1cb4fc;
            case 0x1CB500u: goto label_1cb500;
            case 0x1CB508u: goto label_1cb508;
            case 0x1CB520u: goto label_1cb520;
            case 0x1CB550u: goto label_1cb550;
            case 0x1CB558u: goto label_1cb558;
            case 0x1CB570u: goto label_1cb570;
            case 0x1CB578u: goto label_1cb578;
            case 0x1CB58Cu: goto label_1cb58c;
            case 0x1CB590u: goto label_1cb590;
            case 0x1CB598u: goto label_1cb598;
            case 0x1CB5CCu: goto label_1cb5cc;
            case 0x1CB5F0u: goto label_1cb5f0;
            case 0x1CB608u: goto label_1cb608;
            case 0x1CB618u: goto label_1cb618;
            case 0x1CB61Cu: goto label_1cb61c;
            case 0x1CB624u: goto label_1cb624;
            case 0x1CB640u: goto label_1cb640;
            case 0x1CB67Cu: goto label_1cb67c;
            case 0x1CB684u: goto label_1cb684;
            case 0x1CB68Cu: goto label_1cb68c;
            case 0x1CB6B8u: goto label_1cb6b8;
            case 0x1CB6C0u: goto label_1cb6c0;
            case 0x1CB6C8u: goto label_1cb6c8;
            case 0x1CB6D0u: goto label_1cb6d0;
            case 0x1CB6D4u: goto label_1cb6d4;
            case 0x1CB6ECu: goto label_1cb6ec;
            case 0x1CB708u: goto label_1cb708;
            case 0x1CB710u: goto label_1cb710;
            case 0x1CB72Cu: goto label_1cb72c;
            case 0x1CB748u: goto label_1cb748;
            case 0x1CB75Cu: goto label_1cb75c;
            case 0x1CB778u: goto label_1cb778;
            case 0x1CB790u: goto label_1cb790;
            case 0x1CB794u: goto label_1cb794;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB7A4u;
    // 0x1cb7a4: 0x0  nop
    ctx->pc = 0x1cb7a4u;
    // NOP
    // 0x1cb7a8: 0x0  nop
    ctx->pc = 0x1cb7a8u;
    // NOP
    // 0x1cb7ac: 0x0  nop
    ctx->pc = 0x1cb7acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
