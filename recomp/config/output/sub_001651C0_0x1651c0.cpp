#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001651C0
// Address: 0x1651c0 - 0x1652c8
void sub_001651C0_0x1651c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001651C0_0x1651c0");
#endif

    switch (ctx->pc) {
        case 0x1651fcu: goto label_1651fc;
        case 0x165220u: goto label_165220;
        case 0x165244u: goto label_165244;
        case 0x16526cu: goto label_16526c;
        default: break;
    }

    ctx->pc = 0x1651c0u;

    // 0x1651c0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1651c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1651c4: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x1651c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x1651c8: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x1651c8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1651cc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1651ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1651d0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1651d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1651d4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1651d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1651d8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1651d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1651dc: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x1651dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x1651e0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1651e0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1651e4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1651e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1651e8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1651e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1651ec: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1651ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1651f0: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x1651f0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x1651f4: 0xc05a660  jal         func_169980
    ctx->pc = 0x1651F4u;
    SET_GPR_U32(ctx, 31, 0x1651FCu);
    ctx->pc = 0x1651F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1651F4u;
            // 0x1651f8: 0x8e931b74  lw          $s3, 0x1B74($s4) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 7028)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169980u;
    if (runtime->hasFunction(0x169980u)) {
        auto targetFn = runtime->lookupFunction(0x169980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1651FCu; }
        if (ctx->pc != 0x1651FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169980_0x169980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1651FCu; }
        if (ctx->pc != 0x1651FCu) { return; }
    }
    ctx->pc = 0x1651FCu;
label_1651fc:
    // 0x1651fc: 0x2842006c  slti        $v0, $v0, 0x6C
    ctx->pc = 0x1651fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)108) ? 1 : 0);
    // 0x165200: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x165200u;
    {
        const bool branch_taken_0x165200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x165204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165200u;
            // 0x165204: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165200) {
            ctx->pc = 0x165218u;
            goto label_165218;
        }
    }
    ctx->pc = 0x165208u;
    // 0x165208: 0x3c020016  lui         $v0, 0x16
    ctx->pc = 0x165208u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
    // 0x16520c: 0x24424fe8  addiu       $v0, $v0, 0x4FE8
    ctx->pc = 0x16520cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20456));
    // 0x165210: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x165210u;
    {
        const bool branch_taken_0x165210 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x165214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165210u;
            // 0x165214: 0xae62003c  sw          $v0, 0x3C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165210) {
            ctx->pc = 0x1652A4u;
            goto label_1652a4;
        }
    }
    ctx->pc = 0x165218u;
label_165218:
    // 0x165218: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x165218u;
    {
        const bool branch_taken_0x165218 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16521Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165218u;
            // 0x16521c: 0x2652ffee  addiu       $s2, $s2, -0x12 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967278));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165218) {
            ctx->pc = 0x165224u;
            goto label_165224;
        }
    }
    ctx->pc = 0x165220u;
label_165220:
    // 0x165220: 0x26310012  addiu       $s1, $s1, 0x12
    ctx->pc = 0x165220u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 18));
label_165224:
    // 0x165224: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x165224u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x165228: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x165228u;
    {
        const bool branch_taken_0x165228 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x165228) {
            ctx->pc = 0x16522Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165228u;
            // 0x16522c: 0xaeb10000  sw          $s1, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16525Cu;
            goto label_16525c;
        }
    }
    ctx->pc = 0x165230u;
    // 0x165230: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x165230u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x165234: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165234u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165238: 0x24a505e0  addiu       $a1, $a1, 0x5E0
    ctx->pc = 0x165238u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1504));
    // 0x16523c: 0xc041e86  jal         func_107A18
    ctx->pc = 0x16523Cu;
    SET_GPR_U32(ctx, 31, 0x165244u);
    ctx->pc = 0x165240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16523Cu;
            // 0x165240: 0x24060012  addiu       $a2, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165244u; }
        if (ctx->pc != 0x165244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165244u; }
        if (ctx->pc != 0x165244u) { return; }
    }
    ctx->pc = 0x165244u;
label_165244:
    // 0x165244: 0x1040fff6  beqz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x165244u;
    {
        const bool branch_taken_0x165244 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x165248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165244u;
            // 0x165248: 0x26100012  addiu       $s0, $s0, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165244) {
            ctx->pc = 0x165220u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_165220;
        }
    }
    ctx->pc = 0x16524Cu;
    // 0x16524c: 0x3c020016  lui         $v0, 0x16
    ctx->pc = 0x16524cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
    // 0x165250: 0x24424fe8  addiu       $v0, $v0, 0x4FE8
    ctx->pc = 0x165250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20456));
    // 0x165254: 0xae62003c  sw          $v0, 0x3C($s3)
    ctx->pc = 0x165254u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
    // 0x165258: 0xaeb10000  sw          $s1, 0x0($s5)
    ctx->pc = 0x165258u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 17));
label_16525c:
    // 0x16525c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16525cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165260: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x165260u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165264: 0xc0594b2  jal         func_1652C8
    ctx->pc = 0x165264u;
    SET_GPR_U32(ctx, 31, 0x16526Cu);
    ctx->pc = 0x165268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165264u;
            // 0x165268: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1652C8u;
    if (runtime->hasFunction(0x1652C8u)) {
        auto targetFn = runtime->lookupFunction(0x1652C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16526Cu; }
        if (ctx->pc != 0x16526Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001652C8_0x1652c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16526Cu; }
        if (ctx->pc != 0x16526Cu) { return; }
    }
    ctx->pc = 0x16526Cu;
label_16526c:
    // 0x16526c: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x16526Cu;
    {
        const bool branch_taken_0x16526c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x165270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16526Cu;
            // 0x165270: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16526c) {
            ctx->pc = 0x1652A8u;
            goto label_1652a8;
        }
    }
    ctx->pc = 0x165274u;
    // 0x165274: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x165274u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165278: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x165278u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x16527c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16527cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x165280: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x165280u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x165284: 0x222001a  div         $zero, $s1, $v0
    ctx->pc = 0x165284u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x165288: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x165288u;
    {
        const bool branch_taken_0x165288 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x165288) {
            ctx->pc = 0x16528Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165288u;
            // 0x16528c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x165290u;
            goto label_165290;
        }
    }
    ctx->pc = 0x165290u;
label_165290:
    // 0x165290: 0x8e630038  lw          $v1, 0x38($s3)
    ctx->pc = 0x165290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x165294: 0x2012  mflo        $a0
    ctx->pc = 0x165294u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x165298: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x165298u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x16529c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x16529cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1652a0: 0xae630038  sw          $v1, 0x38($s3)
    ctx->pc = 0x1652a0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 56), GPR_U32(ctx, 3));
label_1652a4:
    // 0x1652a4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1652a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1652a8:
    // 0x1652a8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1652a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1652ac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1652acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1652b0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1652b0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1652b4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1652b4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1652b8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1652b8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1652bc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1652bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1652c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1652C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1652C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1652C0u;
            // 0x1652c4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1651FCu: goto label_1651fc;
            case 0x165218u: goto label_165218;
            case 0x165220u: goto label_165220;
            case 0x165224u: goto label_165224;
            case 0x165244u: goto label_165244;
            case 0x16525Cu: goto label_16525c;
            case 0x16526Cu: goto label_16526c;
            case 0x165290u: goto label_165290;
            case 0x1652A4u: goto label_1652a4;
            case 0x1652A8u: goto label_1652a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1652C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
