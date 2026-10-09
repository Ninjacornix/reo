#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C6F8
// Address: 0x13c6f8 - 0x13c7c0
void sub_0013C6F8_0x13c6f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C6F8_0x13c6f8");
#endif

    switch (ctx->pc) {
        case 0x13c740u: goto label_13c740;
        case 0x13c768u: goto label_13c768;
        default: break;
    }

    ctx->pc = 0x13c6f8u;

    // 0x13c6f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13c6f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13c6fc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13c6fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13c700: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x13c700u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c704: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13c704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13c708: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x13c708u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c70c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13c70cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13c710: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13c710u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c714: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13c714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13c718: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x13c718u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c71c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x13c71cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x13c720: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x13c720u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c724: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13c724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13c728: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13c728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13c72c: 0x1a800018  blez        $s4, . + 4 + (0x18 << 2)
    ctx->pc = 0x13C72Cu;
    {
        const bool branch_taken_0x13c72c = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x13C730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C72Cu;
            // 0x13c730: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c72c) {
            ctx->pc = 0x13C790u;
            goto label_13c790;
        }
    }
    ctx->pc = 0x13C734u;
    // 0x13c734: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13c734u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13c738: 0x240882d  daddu       $s1, $s2, $zero
    ctx->pc = 0x13c738u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c73c: 0x2455de90  addiu       $s5, $v0, -0x2170
    ctx->pc = 0x13c73cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958736));
label_13c740:
    // 0x13c740: 0x8ea2000c  lw          $v0, 0xC($s5)
    ctx->pc = 0x13c740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 12)));
    // 0x13c744: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x13c744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c748: 0x8ea50008  lw          $a1, 0x8($s5)
    ctx->pc = 0x13c748u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x13c74c: 0x501818  mult        $v1, $v0, $s0
    ctx->pc = 0x13c74cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x13c750: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x13c750u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x13c754: 0x701021  addu        $v0, $v1, $s0
    ctx->pc = 0x13c754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x13c758: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x13c758u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x13c75c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x13c75cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x13c760: 0xc04f002  jal         func_13C008
    ctx->pc = 0x13C760u;
    SET_GPR_U32(ctx, 31, 0x13C768u);
    ctx->pc = 0x13C764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C760u;
            // 0x13c764: 0x2452821  addu        $a1, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C008u;
    if (runtime->hasFunction(0x13C008u)) {
        auto targetFn = runtime->lookupFunction(0x13C008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C768u; }
        if (ctx->pc != 0x13C768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C008_0x13c008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C768u; }
        if (ctx->pc != 0x13C768u) { return; }
    }
    ctx->pc = 0x13C768u;
label_13c768:
    // 0x13c768: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13C768u;
    {
        const bool branch_taken_0x13c768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C76Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C768u;
            // 0x13c76c: 0x214182a  slt         $v1, $s0, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c768) {
            ctx->pc = 0x13C788u;
            goto label_13c788;
        }
    }
    ctx->pc = 0x13C770u;
    // 0x13c770: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13c770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13c774: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x13c774u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x13c778: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13c778u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13c77c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13C77Cu;
    {
        const bool branch_taken_0x13c77c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13C780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C77Cu;
            // 0x13c780: 0xae630004  sw          $v1, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c77c) {
            ctx->pc = 0x13C798u;
            goto label_13c798;
        }
    }
    ctx->pc = 0x13C784u;
    // 0x13c784: 0x0  nop
    ctx->pc = 0x13c784u;
    // NOP
label_13c788:
    // 0x13c788: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x13C788u;
    {
        const bool branch_taken_0x13c788 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13C78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C788u;
            // 0x13c78c: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13c788) {
            ctx->pc = 0x13C740u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13c740;
        }
    }
    ctx->pc = 0x13C790u;
label_13c790:
    // 0x13c790: 0xae600004  sw          $zero, 0x4($s3)
    ctx->pc = 0x13c790u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 0));
    // 0x13c794: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x13c794u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
label_13c798:
    // 0x13c798: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13c798u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13c79c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13c79cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13c7a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13c7a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13c7a4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13c7a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13c7a8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13c7a8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13c7ac: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13c7acu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13c7b0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x13c7b0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13c7b4: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x13c7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13c7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x13C7B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C7B8u;
            // 0x13c7bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C740u: goto label_13c740;
            case 0x13C768u: goto label_13c768;
            case 0x13C788u: goto label_13c788;
            case 0x13C790u: goto label_13c790;
            case 0x13C798u: goto label_13c798;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
