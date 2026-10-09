#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128738
// Address: 0x128738 - 0x128860
void sub_00128738_0x128738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128738_0x128738");
#endif

    switch (ctx->pc) {
        case 0x128798u: goto label_128798;
        case 0x1287d0u: goto label_1287d0;
        case 0x12881cu: goto label_12881c;
        case 0x128854u: goto label_128854;
        default: break;
    }

    ctx->pc = 0x128738u;

    // 0x128738: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128738u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12873c: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x12873cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x128740: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128740u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x128744: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x128744u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x128748: 0x2508d2d0  addiu       $t0, $t0, -0x2D30
    ctx->pc = 0x128748u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294955728));
    // 0x12874c: 0x24090800  addiu       $t1, $zero, 0x800
    ctx->pc = 0x12874cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x128750: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128754: 0x1024024  and         $t0, $t0, $v0
    ctx->pc = 0x128754u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x128758: 0x804a20a  j           func_128828
    ctx->pc = 0x128758u;
    ctx->pc = 0x12875Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128758u;
            // 0x12875c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128828u;
    goto label_128828;
    ctx->pc = 0x128760u;
    // 0x128760: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x128760u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128764: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x128764u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128768: 0xe0602d  daddu       $t4, $a3, $zero
    ctx->pc = 0x128768u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12876c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x12876cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128770: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x128770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x128774: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x128774u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128778: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x128778u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12877c: 0x180482d  daddu       $t1, $t4, $zero
    ctx->pc = 0x12877cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128780: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128780u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128784: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x128784u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128788: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x128788u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12878c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12878cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x128790: 0xc04a218  jal         func_128860
    ctx->pc = 0x128790u;
    SET_GPR_U32(ctx, 31, 0x128798u);
    ctx->pc = 0x128794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128790u;
            // 0x128794: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128798u; }
        if (ctx->pc != 0x128798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128798u; }
        if (ctx->pc != 0x128798u) { return; }
    }
    ctx->pc = 0x128798u;
label_128798:
    // 0x128798: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x128798u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12879c: 0x3e00008  jr          $ra
    ctx->pc = 0x12879Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1287A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12879Cu;
            // 0x1287a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128798u: goto label_128798;
            case 0x1287D0u: goto label_1287d0;
            case 0x12881Cu: goto label_12881c;
            case 0x128828u: goto label_128828;
            case 0x128854u: goto label_128854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1287A4u;
    // 0x1287a4: 0x0  nop
    ctx->pc = 0x1287a4u;
    // NOP
    // 0x1287a8: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1287a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287ac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1287acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1287b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1287b4: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1287b4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287b8: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x1287b8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287bc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1287bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287c0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1287c0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1287c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1287c8: 0xc04a218  jal         func_128860
    ctx->pc = 0x1287C8u;
    SET_GPR_U32(ctx, 31, 0x1287D0u);
    ctx->pc = 0x1287CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1287C8u;
            // 0x1287cc: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1287D0u; }
        if (ctx->pc != 0x1287D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1287D0u; }
        if (ctx->pc != 0x1287D0u) { return; }
    }
    ctx->pc = 0x1287D0u;
label_1287d0:
    // 0x1287d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1287d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1287d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1287D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1287D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1287D4u;
            // 0x1287d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128798u: goto label_128798;
            case 0x1287D0u: goto label_1287d0;
            case 0x12881Cu: goto label_12881c;
            case 0x128828u: goto label_128828;
            case 0x128854u: goto label_128854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1287DCu;
    // 0x1287dc: 0x0  nop
    ctx->pc = 0x1287dcu;
    // NOP
    // 0x1287e0: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1287e0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287e4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1287e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287e8: 0xe0602d  daddu       $t4, $a3, $zero
    ctx->pc = 0x1287e8u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287ec: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1287ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1287f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1287f4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1287f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287f8: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1287f8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1287fc: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x1287fcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128800: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x128800u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128804: 0x180482d  daddu       $t1, $t4, $zero
    ctx->pc = 0x128804u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128808: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128808u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12880c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12880cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128810: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x128810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x128814: 0xc04a218  jal         func_128860
    ctx->pc = 0x128814u;
    SET_GPR_U32(ctx, 31, 0x12881Cu);
    ctx->pc = 0x128818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128814u;
            // 0x128818: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12881Cu; }
        if (ctx->pc != 0x12881Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12881Cu; }
        if (ctx->pc != 0x12881Cu) { return; }
    }
    ctx->pc = 0x12881Cu;
label_12881c:
    // 0x12881c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12881cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x128820: 0x3e00008  jr          $ra
    ctx->pc = 0x128820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128820u;
            // 0x128824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128798u: goto label_128798;
            case 0x1287D0u: goto label_1287d0;
            case 0x12881Cu: goto label_12881c;
            case 0x128828u: goto label_128828;
            case 0x128854u: goto label_128854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128828u;
label_128828:
    // 0x128828: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x128828u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12882c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x12882cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128830: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x128830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x128834: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x128834u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128838: 0x120582d  daddu       $t3, $t1, $zero
    ctx->pc = 0x128838u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12883c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x12883cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128840: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x128840u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128844: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x128844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128848: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x128848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12884c: 0xc04a218  jal         func_128860
    ctx->pc = 0x12884Cu;
    SET_GPR_U32(ctx, 31, 0x128854u);
    ctx->pc = 0x128850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12884Cu;
            // 0x128850: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128860u;
    if (runtime->hasFunction(0x128860u)) {
        auto targetFn = runtime->lookupFunction(0x128860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128854u; }
        if (ctx->pc != 0x128854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128860_0x128860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128854u; }
        if (ctx->pc != 0x128854u) { return; }
    }
    ctx->pc = 0x128854u;
label_128854:
    // 0x128854: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x128854u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x128858: 0x3e00008  jr          $ra
    ctx->pc = 0x128858u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12885Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128858u;
            // 0x12885c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128798u: goto label_128798;
            case 0x1287D0u: goto label_1287d0;
            case 0x12881Cu: goto label_12881c;
            case 0x128828u: goto label_128828;
            case 0x128854u: goto label_128854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128860u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
