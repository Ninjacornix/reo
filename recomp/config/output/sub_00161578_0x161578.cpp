#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161578
// Address: 0x161578 - 0x1618b0
void sub_00161578_0x161578(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161578_0x161578");
#endif

    switch (ctx->pc) {
        case 0x1615d8u: goto label_1615d8;
        case 0x1615fcu: goto label_1615fc;
        case 0x161630u: goto label_161630;
        case 0x1616b4u: goto label_1616b4;
        case 0x1616e8u: goto label_1616e8;
        case 0x1616fcu: goto label_1616fc;
        case 0x16173cu: goto label_16173c;
        case 0x161768u: goto label_161768;
        case 0x16179cu: goto label_16179c;
        case 0x1617b0u: goto label_1617b0;
        case 0x1617d0u: goto label_1617d0;
        case 0x161804u: goto label_161804;
        case 0x161830u: goto label_161830;
        case 0x161864u: goto label_161864;
        case 0x161878u: goto label_161878;
        case 0x161898u: goto label_161898;
        default: break;
    }

    ctx->pc = 0x161578u;

label_161578:
    // 0x161578: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16157c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16157cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161580: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x161580u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x161584: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161584u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161588: 0x805f518  j           func_17D460
    ctx->pc = 0x161588u;
    ctx->pc = 0x16158Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161588u;
            // 0x16158c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D460u;
    {
        auto targetFn = runtime->lookupFunction(0x17D460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x161590u;
    // 0x161590: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161594: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161598: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161598u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16159c: 0x805855e  j           func_161578
    ctx->pc = 0x16159Cu;
    ctx->pc = 0x1615A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16159Cu;
            // 0x1615a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161578u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_161578;
    ctx->pc = 0x1615A4u;
    // 0x1615a4: 0x0  nop
    ctx->pc = 0x1615a4u;
    // NOP
    // 0x1615a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1615a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1615ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1615acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1615b0: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x1615b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x1615b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1615b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1615b8: 0x805f51a  j           func_17D468
    ctx->pc = 0x1615B8u;
    ctx->pc = 0x1615BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1615B8u;
            // 0x1615bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D468_0x17d468(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1615C0u;
    // 0x1615c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1615c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1615c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1615c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1615c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1615c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1615cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1615ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1615d0: 0x80585a2  j           func_161688
    ctx->pc = 0x1615D0u;
    ctx->pc = 0x1615D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1615D0u;
            // 0x1615d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161688u;
    goto label_161688;
    ctx->pc = 0x1615D8u;
label_1615d8:
    // 0x1615d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1615d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1615dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1615dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1615e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1615e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1615e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1615e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1615e8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1615e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1615ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1615ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1615f0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1615f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1615f4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1615F4u;
    SET_GPR_U32(ctx, 31, 0x1615FCu);
    ctx->pc = 0x1615F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1615F4u;
            // 0x1615f8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1615FCu; }
        if (ctx->pc != 0x1615FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1615FCu; }
        if (ctx->pc != 0x1615FCu) { return; }
    }
    ctx->pc = 0x1615FCu;
label_1615fc:
    // 0x1615fc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1615FCu;
    {
        const bool branch_taken_0x1615fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1615FCu;
            // 0x161600: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1615fc) {
            ctx->pc = 0x161628u;
            goto label_161628;
        }
    }
    ctx->pc = 0x161604u;
    // 0x161604: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161604u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161608: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161608u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16160c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16160cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161610: 0x2484fd28  addiu       $a0, $a0, -0x2D8
    ctx->pc = 0x161610u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966568));
    // 0x161614: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161614u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161618: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161618u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16161c: 0x8058dd4  j           func_163750
    ctx->pc = 0x16161Cu;
    ctx->pc = 0x161620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16161Cu;
            // 0x161620: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161624u;
    // 0x161624: 0x0  nop
    ctx->pc = 0x161624u;
    // NOP
label_161628:
    // 0x161628: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161628u;
    SET_GPR_U32(ctx, 31, 0x161630u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161630u; }
        if (ctx->pc != 0x161630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161630u; }
        if (ctx->pc != 0x161630u) { return; }
    }
    ctx->pc = 0x161630u;
label_161630:
    // 0x161630: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161634: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x161634u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161638: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161638u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16163c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16163cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161640: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161640u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161644: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161644u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161648: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16164c: 0x805f49a  j           func_17D268
    ctx->pc = 0x16164Cu;
    ctx->pc = 0x161650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16164Cu;
            // 0x161650: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D268u;
    if (runtime->hasFunction(0x17D268u)) {
        auto targetFn = runtime->lookupFunction(0x17D268u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D268_0x17d268(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161654u;
    // 0x161654: 0x0  nop
    ctx->pc = 0x161654u;
    // NOP
    // 0x161658: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16165c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16165cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161660: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161664: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161664u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161668: 0x80585a2  j           func_161688
    ctx->pc = 0x161668u;
    ctx->pc = 0x16166Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161668u;
            // 0x16166c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161688u;
    goto label_161688;
    ctx->pc = 0x161670u;
    // 0x161670: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161674: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161678: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16167c: 0x8058576  j           func_1615D8
    ctx->pc = 0x16167Cu;
    ctx->pc = 0x161680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16167Cu;
            // 0x161680: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1615D8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1615d8;
    ctx->pc = 0x161684u;
    // 0x161684: 0x0  nop
    ctx->pc = 0x161684u;
    // NOP
label_161688:
    // 0x161688: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16168c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16168cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161690: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161694: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161698: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x161698u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16169c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16169cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1616a0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1616a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616a4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1616a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1616a8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1616a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1616ac: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1616ACu;
    SET_GPR_U32(ctx, 31, 0x1616B4u);
    ctx->pc = 0x1616B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1616ACu;
            // 0x1616b0: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616B4u; }
        if (ctx->pc != 0x1616B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616B4u; }
        if (ctx->pc != 0x1616B4u) { return; }
    }
    ctx->pc = 0x1616B4u;
label_1616b4:
    // 0x1616b4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1616B4u;
    {
        const bool branch_taken_0x1616b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1616B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1616B4u;
            // 0x1616b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1616b4) {
            ctx->pc = 0x1616E0u;
            goto label_1616e0;
        }
    }
    ctx->pc = 0x1616BCu;
    // 0x1616bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1616bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1616c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1616c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1616c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1616c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1616c8: 0x2484fd68  addiu       $a0, $a0, -0x298
    ctx->pc = 0x1616c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966632));
    // 0x1616cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1616ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1616d0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1616d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1616d4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1616d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1616d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1616D8u;
    ctx->pc = 0x1616DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1616D8u;
            // 0x1616dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1616E0u;
label_1616e0:
    // 0x1616e0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1616E0u;
    SET_GPR_U32(ctx, 31, 0x1616E8u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616E8u; }
        if (ctx->pc != 0x1616E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616E8u; }
        if (ctx->pc != 0x1616E8u) { return; }
    }
    ctx->pc = 0x1616E8u;
label_1616e8:
    // 0x1616e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1616e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1616ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616f0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1616f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1616f4: 0xc05f496  jal         func_17D258
    ctx->pc = 0x1616F4u;
    SET_GPR_U32(ctx, 31, 0x1616FCu);
    ctx->pc = 0x1616F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1616F4u;
            // 0x1616f8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D258u;
    if (runtime->hasFunction(0x17D258u)) {
        auto targetFn = runtime->lookupFunction(0x17D258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616FCu; }
        if (ctx->pc != 0x1616FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D258_0x17d258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1616FCu; }
        if (ctx->pc != 0x1616FCu) { return; }
    }
    ctx->pc = 0x1616FCu;
label_1616fc:
    // 0x1616fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1616fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161700: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x161700u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161704: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x161704u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161708: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161708u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16170c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16170cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161710: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161710u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161714: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x161714u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x161718: 0x805f4a0  j           func_17D280
    ctx->pc = 0x161718u;
    ctx->pc = 0x16171Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161718u;
            // 0x16171c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D280u;
    {
        auto targetFn = runtime->lookupFunction(0x17D280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x161720u;
    // 0x161720: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161724: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161728: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161728u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16172c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16172cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161730: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x161730u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x161734: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161734u;
    SET_GPR_U32(ctx, 31, 0x16173Cu);
    ctx->pc = 0x161738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161734u;
            // 0x161738: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16173Cu; }
        if (ctx->pc != 0x16173Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16173Cu; }
        if (ctx->pc != 0x16173Cu) { return; }
    }
    ctx->pc = 0x16173Cu;
label_16173c:
    // 0x16173c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16173Cu;
    {
        const bool branch_taken_0x16173c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16173Cu;
            // 0x161740: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16173c) {
            ctx->pc = 0x161760u;
            goto label_161760;
        }
    }
    ctx->pc = 0x161744u;
    // 0x161744: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161744u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16174c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16174cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161750: 0x2484fda0  addiu       $a0, $a0, -0x260
    ctx->pc = 0x161750u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966688));
    // 0x161754: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161758: 0x8058dd4  j           func_163750
    ctx->pc = 0x161758u;
    ctx->pc = 0x16175Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161758u;
            // 0x16175c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161760u;
label_161760:
    // 0x161760: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161760u;
    SET_GPR_U32(ctx, 31, 0x161768u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161768u; }
        if (ctx->pc != 0x161768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161768u; }
        if (ctx->pc != 0x161768u) { return; }
    }
    ctx->pc = 0x161768u;
label_161768:
    // 0x161768: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161768u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16176c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16176cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161770: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161770u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161774: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161774u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161778: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161778u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16177c: 0x805f4f0  j           func_17D3C0
    ctx->pc = 0x16177Cu;
    ctx->pc = 0x161780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16177Cu;
            // 0x161780: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3C0u;
    {
        auto targetFn = runtime->lookupFunction(0x17D3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x161784u;
    // 0x161784: 0x0  nop
    ctx->pc = 0x161784u;
    // NOP
    // 0x161788: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161788u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16178c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16178cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161790: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161794: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161794u;
    SET_GPR_U32(ctx, 31, 0x16179Cu);
    ctx->pc = 0x161798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161794u;
            // 0x161798: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16179Cu; }
        if (ctx->pc != 0x16179Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16179Cu; }
        if (ctx->pc != 0x16179Cu) { return; }
    }
    ctx->pc = 0x16179Cu;
label_16179c:
    // 0x16179c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16179Cu;
    {
        const bool branch_taken_0x16179c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1617A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16179Cu;
            // 0x1617a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16179c) {
            ctx->pc = 0x1617C8u;
            goto label_1617c8;
        }
    }
    ctx->pc = 0x1617A4u;
    // 0x1617a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1617a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1617a8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1617A8u;
    SET_GPR_U32(ctx, 31, 0x1617B0u);
    ctx->pc = 0x1617ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1617A8u;
            // 0x1617ac: 0x2484fdd8  addiu       $a0, $a0, -0x228 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617B0u; }
        if (ctx->pc != 0x1617B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617B0u; }
        if (ctx->pc != 0x1617B0u) { return; }
    }
    ctx->pc = 0x1617B0u;
label_1617b0:
    // 0x1617b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1617b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1617b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1617b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1617b8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1617b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1617bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1617BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1617C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1617BCu;
            // 0x1617c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161578u: goto label_161578;
            case 0x1615D8u: goto label_1615d8;
            case 0x1615FCu: goto label_1615fc;
            case 0x161628u: goto label_161628;
            case 0x161630u: goto label_161630;
            case 0x161688u: goto label_161688;
            case 0x1616B4u: goto label_1616b4;
            case 0x1616E0u: goto label_1616e0;
            case 0x1616E8u: goto label_1616e8;
            case 0x1616FCu: goto label_1616fc;
            case 0x16173Cu: goto label_16173c;
            case 0x161760u: goto label_161760;
            case 0x161768u: goto label_161768;
            case 0x16179Cu: goto label_16179c;
            case 0x1617B0u: goto label_1617b0;
            case 0x1617C8u: goto label_1617c8;
            case 0x1617D0u: goto label_1617d0;
            case 0x161804u: goto label_161804;
            case 0x161828u: goto label_161828;
            case 0x161830u: goto label_161830;
            case 0x161864u: goto label_161864;
            case 0x161878u: goto label_161878;
            case 0x161890u: goto label_161890;
            case 0x161898u: goto label_161898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1617C4u;
    // 0x1617c4: 0x0  nop
    ctx->pc = 0x1617c4u;
    // NOP
label_1617c8:
    // 0x1617c8: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1617C8u;
    SET_GPR_U32(ctx, 31, 0x1617D0u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617D0u; }
        if (ctx->pc != 0x1617D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617D0u; }
        if (ctx->pc != 0x1617D0u) { return; }
    }
    ctx->pc = 0x1617D0u;
label_1617d0:
    // 0x1617d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1617d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1617d4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1617d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1617d8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1617d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1617dc: 0x805f4f2  j           func_17D3C8
    ctx->pc = 0x1617DCu;
    ctx->pc = 0x1617E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1617DCu;
            // 0x1617e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3C8u;
    {
        auto targetFn = runtime->lookupFunction(0x17D3C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1617E4u;
    // 0x1617e4: 0x0  nop
    ctx->pc = 0x1617e4u;
    // NOP
    // 0x1617e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1617e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1617ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1617ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1617f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1617f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1617f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1617f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1617f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1617f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1617fc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1617FCu;
    SET_GPR_U32(ctx, 31, 0x161804u);
    ctx->pc = 0x161800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1617FCu;
            // 0x161800: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161804u; }
        if (ctx->pc != 0x161804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161804u; }
        if (ctx->pc != 0x161804u) { return; }
    }
    ctx->pc = 0x161804u;
label_161804:
    // 0x161804: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x161804u;
    {
        const bool branch_taken_0x161804 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161804u;
            // 0x161808: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161804) {
            ctx->pc = 0x161828u;
            goto label_161828;
        }
    }
    ctx->pc = 0x16180Cu;
    // 0x16180c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16180cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161810: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161810u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161814: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161814u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161818: 0x2484fe10  addiu       $a0, $a0, -0x1F0
    ctx->pc = 0x161818u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966800));
    // 0x16181c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16181cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161820: 0x8058dd4  j           func_163750
    ctx->pc = 0x161820u;
    ctx->pc = 0x161824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161820u;
            // 0x161824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161828u;
label_161828:
    // 0x161828: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161828u;
    SET_GPR_U32(ctx, 31, 0x161830u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161830u; }
        if (ctx->pc != 0x161830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161830u; }
        if (ctx->pc != 0x161830u) { return; }
    }
    ctx->pc = 0x161830u;
label_161830:
    // 0x161830: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161830u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161834: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161834u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161838: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161838u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16183c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16183cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161840: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161840u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161844: 0x805f4f4  j           func_17D3D0
    ctx->pc = 0x161844u;
    ctx->pc = 0x161848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161844u;
            // 0x161848: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3D0u;
    {
        auto targetFn = runtime->lookupFunction(0x17D3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x16184Cu;
    // 0x16184c: 0x0  nop
    ctx->pc = 0x16184cu;
    // NOP
    // 0x161850: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161854: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161858: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16185c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16185Cu;
    SET_GPR_U32(ctx, 31, 0x161864u);
    ctx->pc = 0x161860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16185Cu;
            // 0x161860: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161864u; }
        if (ctx->pc != 0x161864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161864u; }
        if (ctx->pc != 0x161864u) { return; }
    }
    ctx->pc = 0x161864u;
label_161864:
    // 0x161864: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x161864u;
    {
        const bool branch_taken_0x161864 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161864u;
            // 0x161868: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161864) {
            ctx->pc = 0x161890u;
            goto label_161890;
        }
    }
    ctx->pc = 0x16186Cu;
    // 0x16186c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16186cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161870: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161870u;
    SET_GPR_U32(ctx, 31, 0x161878u);
    ctx->pc = 0x161874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161870u;
            // 0x161874: 0x2484fe48  addiu       $a0, $a0, -0x1B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161878u; }
        if (ctx->pc != 0x161878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161878u; }
        if (ctx->pc != 0x161878u) { return; }
    }
    ctx->pc = 0x161878u;
label_161878:
    // 0x161878: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x161878u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16187c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16187cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161880: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161884: 0x3e00008  jr          $ra
    ctx->pc = 0x161884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161884u;
            // 0x161888: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161578u: goto label_161578;
            case 0x1615D8u: goto label_1615d8;
            case 0x1615FCu: goto label_1615fc;
            case 0x161628u: goto label_161628;
            case 0x161630u: goto label_161630;
            case 0x161688u: goto label_161688;
            case 0x1616B4u: goto label_1616b4;
            case 0x1616E0u: goto label_1616e0;
            case 0x1616E8u: goto label_1616e8;
            case 0x1616FCu: goto label_1616fc;
            case 0x16173Cu: goto label_16173c;
            case 0x161760u: goto label_161760;
            case 0x161768u: goto label_161768;
            case 0x16179Cu: goto label_16179c;
            case 0x1617B0u: goto label_1617b0;
            case 0x1617C8u: goto label_1617c8;
            case 0x1617D0u: goto label_1617d0;
            case 0x161804u: goto label_161804;
            case 0x161828u: goto label_161828;
            case 0x161830u: goto label_161830;
            case 0x161864u: goto label_161864;
            case 0x161878u: goto label_161878;
            case 0x161890u: goto label_161890;
            case 0x161898u: goto label_161898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16188Cu;
    // 0x16188c: 0x0  nop
    ctx->pc = 0x16188cu;
    // NOP
label_161890:
    // 0x161890: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161890u;
    SET_GPR_U32(ctx, 31, 0x161898u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161898u; }
        if (ctx->pc != 0x161898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161898u; }
        if (ctx->pc != 0x161898u) { return; }
    }
    ctx->pc = 0x161898u;
label_161898:
    // 0x161898: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161898u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16189c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16189cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1618a0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1618a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1618a4: 0x805f4f6  j           func_17D3D8
    ctx->pc = 0x1618A4u;
    ctx->pc = 0x1618A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1618A4u;
            // 0x1618a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3D8u;
    {
        auto targetFn = runtime->lookupFunction(0x17D3D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1618ACu;
    // 0x1618ac: 0x0  nop
    ctx->pc = 0x1618acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
