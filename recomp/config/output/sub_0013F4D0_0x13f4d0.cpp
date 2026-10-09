#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F4D0
// Address: 0x13f4d0 - 0x13f58c
void sub_0013F4D0_0x13f4d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F4D0_0x13f4d0");
#endif

    switch (ctx->pc) {
        case 0x13f4fcu: goto label_13f4fc;
        case 0x13f570u: goto label_13f570;
        default: break;
    }

    ctx->pc = 0x13f4d0u;

    // 0x13f4d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13f4d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13f4d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f4d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f4d8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13f4d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f4dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f4dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f4e0: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x13f4e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f4e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f4e8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13f4e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f4ec: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13f4ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13f4f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13f4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13f4f4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F4F4u;
    SET_GPR_U32(ctx, 31, 0x13F4FCu);
    ctx->pc = 0x13F4F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4F4u;
            // 0x13f4f8: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F4FCu; }
        if (ctx->pc != 0x13F4FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F4FCu; }
        if (ctx->pc != 0x13F4FCu) { return; }
    }
    ctx->pc = 0x13F4FCu;
label_13f4fc:
    // 0x13f4fc: 0x16400004  bnez        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F4FCu;
    {
        const bool branch_taken_0x13f4fc = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13F500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4FCu;
            // 0x13f500: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f4fc) {
            ctx->pc = 0x13F510u;
            goto label_13f510;
        }
    }
    ctx->pc = 0x13F504u;
    // 0x13f504: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13f504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13f508: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x13F508u;
    {
        const bool branch_taken_0x13f508 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F508u;
            // 0x13f50c: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f508) {
            ctx->pc = 0x13F570u;
            goto label_13f570;
        }
    }
    ctx->pc = 0x13F510u;
label_13f510:
    // 0x13f510: 0x56420011  bnel        $s2, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x13F510u;
    {
        const bool branch_taken_0x13f510 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13f510) {
            ctx->pc = 0x13F514u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F510u;
            // 0x13f514: 0x8e22001c  lw          $v0, 0x1C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F558u;
            goto label_13f558;
        }
    }
    ctx->pc = 0x13F518u;
    // 0x13f518: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x13f518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x13f51c: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x13f51cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13f520: 0x53182a  slt         $v1, $v0, $s3
    ctx->pc = 0x13f520u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13f524: 0x263100a  movz        $v0, $s3, $v1
    ctx->pc = 0x13f524u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 19));
    // 0x13f528: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x13f528u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x13f52c: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x13f52cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x13f530: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x13f530u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x13f534: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x13f534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13f538: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13f538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13f53c: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x13f53cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x13f540: 0xae050000  sw          $a1, 0x0($s0)
    ctx->pc = 0x13f540u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
    // 0x13f544: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x13f544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x13f548: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13f548u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13f54c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13F54Cu;
    {
        const bool branch_taken_0x13f54c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F54Cu;
            // 0x13f550: 0xae23000c  sw          $v1, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f54c) {
            ctx->pc = 0x13F570u;
            goto label_13f570;
        }
    }
    ctx->pc = 0x13F554u;
    // 0x13f554: 0x0  nop
    ctx->pc = 0x13f554u;
    // NOP
label_13f558:
    // 0x13f558: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13f558u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13f55c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F55Cu;
    {
        const bool branch_taken_0x13f55c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F55Cu;
            // 0x13f560: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f55c) {
            ctx->pc = 0x13F570u;
            goto label_13f570;
        }
    }
    ctx->pc = 0x13F564u;
    // 0x13f564: 0x8e240020  lw          $a0, 0x20($s1)
    ctx->pc = 0x13f564u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13f568: 0x40f809  jalr        $v0
    ctx->pc = 0x13F568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F570u);
        ctx->pc = 0x13F56Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F568u;
            // 0x13f56c: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F570u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F570u; }
            if (ctx->pc != 0x13F570u) { return; }
        }
        }
    }
    ctx->pc = 0x13F570u;
label_13f570:
    // 0x13f570: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f570u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f574: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f574u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f57c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13f57cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f580: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13f580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13f584: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F584u;
    ctx->pc = 0x13F588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F584u;
            // 0x13f588: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F58Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
