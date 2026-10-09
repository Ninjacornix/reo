#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133630
// Address: 0x133630 - 0x133704
void sub_00133630_0x133630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133630_0x133630");
#endif

    switch (ctx->pc) {
        case 0x133690u: goto label_133690;
        case 0x133698u: goto label_133698;
        case 0x1336a4u: goto label_1336a4;
        case 0x1336b8u: goto label_1336b8;
        case 0x1336e0u: goto label_1336e0;
        default: break;
    }

    ctx->pc = 0x133630u;

    // 0x133630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x133630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x133634: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133638: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133638u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13363c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13363cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133640: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x133640u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133644: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x133644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x133648: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x133648u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13364c: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13364Cu;
    {
        const bool branch_taken_0x13364c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x133650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13364Cu;
            // 0x133650: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13364c) {
            ctx->pc = 0x133664u;
            goto label_133664;
        }
    }
    ctx->pc = 0x133654u;
    // 0x133654: 0x52200004  beql        $s1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x133654u;
    {
        const bool branch_taken_0x133654 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x133654) {
            ctx->pc = 0x133658u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133654u;
            // 0x133658: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133668u;
            goto label_133668;
        }
    }
    ctx->pc = 0x13365Cu;
    // 0x13365c: 0x641000a  bgez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x13365Cu;
    {
        const bool branch_taken_0x13365c = (GPR_S64(ctx, 18) >= 0);
        if (branch_taken_0x13365c) {
            ctx->pc = 0x133688u;
            goto label_133688;
        }
    }
    ctx->pc = 0x133664u;
label_133664:
    // 0x133664: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133664u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_133668:
    // 0x133668: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133668u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13366c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13366cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133670: 0x2484b600  addiu       $a0, $a0, -0x4A00
    ctx->pc = 0x133670u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948352));
    // 0x133674: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133674u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133678: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x133678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13367c: 0x804a034  j           func_1280D0
    ctx->pc = 0x13367Cu;
    ctx->pc = 0x133680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13367Cu;
            // 0x133680: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133684u;
    // 0x133684: 0x0  nop
    ctx->pc = 0x133684u;
    // NOP
label_133688:
    // 0x133688: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x133688u;
    SET_GPR_U32(ctx, 31, 0x133690u);
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133690u; }
        if (ctx->pc != 0x133690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133690u; }
        if (ctx->pc != 0x133690u) { return; }
    }
    ctx->pc = 0x133690u;
label_133690:
    // 0x133690: 0xc049938  jal         func_1264E0
    ctx->pc = 0x133690u;
    SET_GPR_U32(ctx, 31, 0x133698u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133698u; }
        if (ctx->pc != 0x133698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133698u; }
        if (ctx->pc != 0x133698u) { return; }
    }
    ctx->pc = 0x133698u;
label_133698:
    // 0x133698: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x133698u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13369c: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x13369Cu;
    SET_GPR_U32(ctx, 31, 0x1336A4u);
    ctx->pc = 0x1336A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13369Cu;
            // 0x1336a0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336A4u; }
        if (ctx->pc != 0x1336A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336A4u; }
        if (ctx->pc != 0x1336A4u) { return; }
    }
    ctx->pc = 0x1336A4u;
label_1336a4:
    // 0x1336a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1336a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1336a8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1336A8u;
    {
        const bool branch_taken_0x1336a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1336ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1336A8u;
            // 0x1336ac: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1336a8) {
            ctx->pc = 0x1336D8u;
            goto label_1336d8;
        }
    }
    ctx->pc = 0x1336B0u;
    // 0x1336b0: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x1336B0u;
    SET_GPR_U32(ctx, 31, 0x1336B8u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336B8u; }
        if (ctx->pc != 0x1336B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336B8u; }
        if (ctx->pc != 0x1336B8u) { return; }
    }
    ctx->pc = 0x1336B8u;
label_1336b8:
    // 0x1336b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1336b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1336bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1336bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1336c0: 0x2484b630  addiu       $a0, $a0, -0x49D0
    ctx->pc = 0x1336c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948400));
    // 0x1336c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1336c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1336c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1336c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1336cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1336ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1336d0: 0x804a034  j           func_1280D0
    ctx->pc = 0x1336D0u;
    ctx->pc = 0x1336D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1336D0u;
            // 0x1336d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1336D8u;
label_1336d8:
    // 0x1336d8: 0xc04c6d8  jal         func_131B60
    ctx->pc = 0x1336D8u;
    SET_GPR_U32(ctx, 31, 0x1336E0u);
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336E0u; }
        if (ctx->pc != 0x1336E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131B60_0x131b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1336E0u; }
        if (ctx->pc != 0x1336E0u) { return; }
    }
    ctx->pc = 0x1336E0u;
label_1336e0:
    // 0x1336e0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1336e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1336e4: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1336e4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1336e8: 0xa2000098  sb          $zero, 0x98($s0)
    ctx->pc = 0x1336e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x1336ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1336ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1336f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1336f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1336f4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1336f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1336f8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1336f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1336fc: 0x804993e  j           func_1264F8
    ctx->pc = 0x1336FCu;
    ctx->pc = 0x133700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1336FCu;
            // 0x133700: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133704u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
