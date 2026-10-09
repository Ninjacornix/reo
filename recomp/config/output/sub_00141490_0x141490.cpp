#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141490
// Address: 0x141490 - 0x141588
void sub_00141490_0x141490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141490_0x141490");
#endif

    switch (ctx->pc) {
        case 0x1414d0u: goto label_1414d0;
        case 0x141510u: goto label_141510;
        case 0x141544u: goto label_141544;
        case 0x141558u: goto label_141558;
        default: break;
    }

    ctx->pc = 0x141490u;

    // 0x141490: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x141490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x141494: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141494u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x141498: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x141498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x14149c: 0x24509a90  addiu       $s0, $v0, -0x6570
    ctx->pc = 0x14149cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941328));
    // 0x1414a0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1414a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1414a4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1414a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1414a8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1414a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1414ac: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1414acu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1414b0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1414b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1414b4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1414b4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1414b8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1414b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1414bc: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1414bcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1414c0: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1414C0u;
    {
        const bool branch_taken_0x1414c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1414C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1414C0u;
            // 0x1414c4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1414c0) {
            ctx->pc = 0x1414F4u;
            goto label_1414f4;
        }
    }
    ctx->pc = 0x1414C8u;
    // 0x1414c8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1414c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1414cc: 0x200182d  daddu       $v1, $s0, $zero
    ctx->pc = 0x1414ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1414d0:
    // 0x1414d0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1414d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1414d4: 0x24a50014  addiu       $a1, $a1, 0x14
    ctx->pc = 0x1414d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20));
    // 0x1414d8: 0x28820020  slti        $v0, $a0, 0x20
    ctx->pc = 0x1414d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1414dc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1414DCu;
    {
        const bool branch_taken_0x1414dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1414E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1414DCu;
            // 0x1414e0: 0x24630014  addiu       $v1, $v1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1414dc) {
            ctx->pc = 0x1414F4u;
            goto label_1414f4;
        }
    }
    ctx->pc = 0x1414E4u;
    // 0x1414e4: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x1414e4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1414e8: 0x0  nop
    ctx->pc = 0x1414e8u;
    // NOP
    // 0x1414ec: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1414ECu;
    {
        const bool branch_taken_0x1414ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1414F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1414ECu;
            // 0x1414f0: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1414ec) {
            ctx->pc = 0x1414D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1414d0;
        }
    }
    ctx->pc = 0x1414F4u;
label_1414f4:
    // 0x1414f4: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x1414f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1414f8: 0x1083001c  beq         $a0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1414F8u;
    {
        const bool branch_taken_0x1414f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1414FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1414F8u;
            // 0x1414fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1414f8) {
            ctx->pc = 0x14156Cu;
            goto label_14156c;
        }
    }
    ctx->pc = 0x141500u;
    // 0x141500: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x141500u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141504: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x141504u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141508: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x141508u;
    SET_GPR_U32(ctx, 31, 0x141510u);
    ctx->pc = 0x14150Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141508u;
            // 0x14150c: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141510u; }
        if (ctx->pc != 0x141510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141510u; }
        if (ctx->pc != 0x141510u) { return; }
    }
    ctx->pc = 0x141510u;
label_141510:
    // 0x141510: 0xae130004  sw          $s3, 0x4($s0)
    ctx->pc = 0x141510u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 19));
    // 0x141514: 0xae11000c  sw          $s1, 0xC($s0)
    ctx->pc = 0x141514u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 17));
    // 0x141518: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x141518u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14151c: 0xae120008  sw          $s2, 0x8($s0)
    ctx->pc = 0x14151cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 18));
    // 0x141520: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x141520u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141524: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x141524u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x141528: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x141528u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14152c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x14152cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141530: 0xafb30000  sw          $s3, 0x0($sp)
    ctx->pc = 0x141530u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 19));
    // 0x141534: 0xafb20004  sw          $s2, 0x4($sp)
    ctx->pc = 0x141534u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 18));
    // 0x141538: 0xafb10008  sw          $s1, 0x8($sp)
    ctx->pc = 0x141538u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 17));
    // 0x14153c: 0xc04e518  jal         func_139460
    ctx->pc = 0x14153Cu;
    SET_GPR_U32(ctx, 31, 0x141544u);
    ctx->pc = 0x141540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14153Cu;
            // 0x141540: 0xafb0000c  sw          $s0, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141544u; }
        if (ctx->pc != 0x141544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141544u; }
        if (ctx->pc != 0x141544u) { return; }
    }
    ctx->pc = 0x141544u;
label_141544:
    // 0x141544: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x141544u;
    {
        const bool branch_taken_0x141544 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x141548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141544u;
            // 0x141548: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141544) {
            ctx->pc = 0x141560u;
            goto label_141560;
        }
    }
    ctx->pc = 0x14154Cu;
    // 0x14154c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x14154cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141550: 0xc045a12  jal         func_116848
    ctx->pc = 0x141550u;
    SET_GPR_U32(ctx, 31, 0x141558u);
    ctx->pc = 0x141554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141550u;
            // 0x141554: 0x2484db50  addiu       $a0, $a0, -0x24B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141558u; }
        if (ctx->pc != 0x141558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141558u; }
        if (ctx->pc != 0x141558u) { return; }
    }
    ctx->pc = 0x141558u;
label_141558:
    // 0x141558: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x141558u;
    {
        const bool branch_taken_0x141558 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14155Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141558u;
            // 0x14155c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141558) {
            ctx->pc = 0x14156Cu;
            goto label_14156c;
        }
    }
    ctx->pc = 0x141560u;
label_141560:
    // 0x141560: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x141560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141564: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x141564u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141568: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x141568u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
label_14156c:
    // 0x14156c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14156cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141570: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x141570u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141574: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x141574u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141578: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x141578u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14157c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x14157cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x141580: 0x3e00008  jr          $ra
    ctx->pc = 0x141580u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141580u;
            // 0x141584: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1414D0u: goto label_1414d0;
            case 0x1414F4u: goto label_1414f4;
            case 0x141510u: goto label_141510;
            case 0x141544u: goto label_141544;
            case 0x141558u: goto label_141558;
            case 0x141560u: goto label_141560;
            case 0x14156Cu: goto label_14156c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141588u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
