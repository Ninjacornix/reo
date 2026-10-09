#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CCE0
// Address: 0x12cce0 - 0x12ceb8
void sub_0012CCE0_0x12cce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CCE0_0x12cce0");
#endif

    switch (ctx->pc) {
        case 0x12cd20u: goto label_12cd20;
        case 0x12cd3cu: goto label_12cd3c;
        case 0x12cd6cu: goto label_12cd6c;
        case 0x12cd98u: goto label_12cd98;
        case 0x12cdacu: goto label_12cdac;
        case 0x12cdc0u: goto label_12cdc0;
        case 0x12cdd8u: goto label_12cdd8;
        case 0x12cdfcu: goto label_12cdfc;
        case 0x12ce04u: goto label_12ce04;
        case 0x12ce44u: goto label_12ce44;
        case 0x12ce64u: goto label_12ce64;
        case 0x12ce7cu: goto label_12ce7c;
        case 0x12ce94u: goto label_12ce94;
        default: break;
    }

    ctx->pc = 0x12cce0u;

    // 0x12cce0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12cce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12cce4: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x12cce4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x12cce8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12cce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x12ccec: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x12ccecu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ccf0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12ccf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12ccf4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12ccf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ccf8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12ccf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12ccfc: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x12ccfcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cd00: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12cd00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12cd04: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x12cd04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x12cd08: 0x8e710008  lw          $s1, 0x8($s3)
    ctx->pc = 0x12cd08u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x12cd0c: 0x8e700004  lw          $s0, 0x4($s3)
    ctx->pc = 0x12cd0cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x12cd10: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x12cd10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12cd14: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12cd14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12cd18: 0x60f809  jalr        $v1
    ctx->pc = 0x12CD18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12CD20u);
        ctx->pc = 0x12CD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD18u;
            // 0x12cd1c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CD20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CD20u; }
            if (ctx->pc != 0x12CD20u) { return; }
        }
        }
    }
    ctx->pc = 0x12CD20u;
label_12cd20:
    // 0x12cd20: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x12cd20u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12cd24: 0x28c20010  slti        $v0, $a2, 0x10
    ctx->pc = 0x12cd24u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x12cd28: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x12CD28u;
    {
        const bool branch_taken_0x12cd28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12cd28) {
            ctx->pc = 0x12CD2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD28u;
            // 0x12cd2c: 0x8e230000  lw          $v1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12CD58u;
            goto label_12cd58;
        }
    }
    ctx->pc = 0x12CD30u;
    // 0x12cd30: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x12cd30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cd34: 0xc049336  jal         func_124CD8
    ctx->pc = 0x12CD34u;
    SET_GPR_U32(ctx, 31, 0x12CD3Cu);
    ctx->pc = 0x12CD38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD34u;
            // 0x12cd38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124CD8u;
    if (runtime->hasFunction(0x124CD8u)) {
        auto targetFn = runtime->lookupFunction(0x124CD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CD3Cu; }
        if (ctx->pc != 0x12CD3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124CD8_0x124cd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CD3Cu; }
        if (ctx->pc != 0x12CD3Cu) { return; }
    }
    ctx->pc = 0x12CD3Cu;
label_12cd3c:
    // 0x12cd3c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x12cd3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cd40: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x12CD40u;
    {
        const bool branch_taken_0x12cd40 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CD44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD40u;
            // 0x12cd44: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cd40) {
            ctx->pc = 0x12CD54u;
            goto label_12cd54;
        }
    }
    ctx->pc = 0x12CD48u;
    // 0x12cd48: 0x52102a  slt         $v0, $v0, $s2
    ctx->pc = 0x12cd48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x12cd4c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x12CD4Cu;
    {
        const bool branch_taken_0x12cd4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12cd4c) {
            ctx->pc = 0x12CD78u;
            goto label_12cd78;
        }
    }
    ctx->pc = 0x12CD54u;
label_12cd54:
    // 0x12cd54: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12cd54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_12cd58:
    // 0x12cd58: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12cd58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cd5c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12cd5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12cd60: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12cd60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12cd64: 0x40f809  jalr        $v0
    ctx->pc = 0x12CD64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12CD6Cu);
        ctx->pc = 0x12CD68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD64u;
            // 0x12cd68: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CD6Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CD6Cu; }
            if (ctx->pc != 0x12CD6Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12CD6Cu;
label_12cd6c:
    // 0x12cd6c: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x12CD6Cu;
    {
        const bool branch_taken_0x12cd6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD6Cu;
            // 0x12cd70: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cd6c) {
            ctx->pc = 0x12CEA0u;
            goto label_12cea0;
        }
    }
    ctx->pc = 0x12CD74u;
    // 0x12cd74: 0x0  nop
    ctx->pc = 0x12cd74u;
    // NOP
label_12cd78:
    // 0x12cd78: 0x643000f  bgezl       $s2, . + 4 + (0xF << 2)
    ctx->pc = 0x12CD78u;
    {
        const bool branch_taken_0x12cd78 = (GPR_S64(ctx, 18) >= 0);
        if (branch_taken_0x12cd78) {
            ctx->pc = 0x12CD7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD78u;
            // 0x12cd7c: 0xae720098  sw          $s2, 0x98($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 152), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12CDB8u;
            goto label_12cdb8;
        }
    }
    ctx->pc = 0x12CD80u;
    // 0x12cd80: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12cd80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12cd84: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12cd84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cd88: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12cd88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12cd8c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12cd8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12cd90: 0x40f809  jalr        $v0
    ctx->pc = 0x12CD90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12CD98u);
        ctx->pc = 0x12CD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CD90u;
            // 0x12cd94: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CD98u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CD98u; }
            if (ctx->pc != 0x12CD98u) { return; }
        }
        }
    }
    ctx->pc = 0x12CD98u;
label_12cd98:
    // 0x12cd98: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12cd98u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12cd9c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x12cd9cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x12cda0: 0x2484ad50  addiu       $a0, $a0, -0x52B0
    ctx->pc = 0x12cda0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946128));
    // 0x12cda4: 0xc04a04a  jal         func_128128
    ctx->pc = 0x12CDA4u;
    SET_GPR_U32(ctx, 31, 0x12CDACu);
    ctx->pc = 0x12CDA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDA4u;
            // 0x12cda8: 0x24a5ad70  addiu       $a1, $a1, -0x5290 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128128u;
    if (runtime->hasFunction(0x128128u)) {
        auto targetFn = runtime->lookupFunction(0x128128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDACu; }
        if (ctx->pc != 0x12CDACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128128_0x128128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDACu; }
        if (ctx->pc != 0x12CDACu) { return; }
    }
    ctx->pc = 0x12CDACu;
label_12cdac:
    // 0x12cdac: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x12CDACu;
    {
        const bool branch_taken_0x12cdac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CDB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDACu;
            // 0x12cdb0: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cdac) {
            ctx->pc = 0x12CE98u;
            goto label_12ce98;
        }
    }
    ctx->pc = 0x12CDB4u;
    // 0x12cdb4: 0x0  nop
    ctx->pc = 0x12cdb4u;
    // NOP
label_12cdb8:
    // 0x12cdb8: 0xc04939a  jal         func_124E68
    ctx->pc = 0x12CDB8u;
    SET_GPR_U32(ctx, 31, 0x12CDC0u);
    ctx->pc = 0x12CDBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDB8u;
            // 0x12cdbc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDC0u; }
        if (ctx->pc != 0x12CDC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E68_0x124e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDC0u; }
        if (ctx->pc != 0x12CDC0u) { return; }
    }
    ctx->pc = 0x12CDC0u;
label_12cdc0:
    // 0x12cdc0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x12cdc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12cdc4: 0x14430002  bne         $v0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x12CDC4u;
    {
        const bool branch_taken_0x12cdc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12CDC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDC4u;
            // 0x12cdc8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cdc4) {
            ctx->pc = 0x12CDD0u;
            goto label_12cdd0;
        }
    }
    ctx->pc = 0x12CDCCu;
    // 0x12cdcc: 0xa2620003  sb          $v0, 0x3($s3)
    ctx->pc = 0x12cdccu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 2));
label_12cdd0:
    // 0x12cdd0: 0xc04939a  jal         func_124E68
    ctx->pc = 0x12CDD0u;
    SET_GPR_U32(ctx, 31, 0x12CDD8u);
    ctx->pc = 0x12CDD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDD0u;
            // 0x12cdd4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDD8u; }
        if (ctx->pc != 0x12CDD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E68_0x124e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDD8u; }
        if (ctx->pc != 0x12CDD8u) { return; }
    }
    ctx->pc = 0x12CDD8u;
label_12cdd8:
    // 0x12cdd8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x12cdd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12cddc: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x12CDDCu;
    {
        const bool branch_taken_0x12cddc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12CDE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDDCu;
            // 0x12cde0: 0x24030040  addiu       $v1, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cddc) {
            ctx->pc = 0x12CDFCu;
            goto label_12cdfc;
        }
    }
    ctx->pc = 0x12CDE4u;
    // 0x12cde4: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x12cde4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12cde8: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x12cde8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cdec: 0x26640058  addiu       $a0, $s3, 0x58
    ctx->pc = 0x12cdecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 88));
    // 0x12cdf0: 0x28c20041  slti        $v0, $a2, 0x41
    ctx->pc = 0x12cdf0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)65) ? 1 : 0);
    // 0x12cdf4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x12CDF4u;
    SET_GPR_U32(ctx, 31, 0x12CDFCu);
    ctx->pc = 0x12CDF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDF4u;
            // 0x12cdf8: 0x62300a  movz        $a2, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDFCu; }
        if (ctx->pc != 0x12CDFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CDFCu; }
        if (ctx->pc != 0x12CDFCu) { return; }
    }
    ctx->pc = 0x12CDFCu;
label_12cdfc:
    // 0x12cdfc: 0xc04939a  jal         func_124E68
    ctx->pc = 0x12CDFCu;
    SET_GPR_U32(ctx, 31, 0x12CE04u);
    ctx->pc = 0x12CE00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CDFCu;
            // 0x12ce00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E68u;
    if (runtime->hasFunction(0x124E68u)) {
        auto targetFn = runtime->lookupFunction(0x124E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CE04u; }
        if (ctx->pc != 0x12CE04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E68_0x124e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CE04u; }
        if (ctx->pc != 0x12CE04u) { return; }
    }
    ctx->pc = 0x12CE04u;
label_12ce04:
    // 0x12ce04: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x12ce04u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce08: 0x2462fff6  addiu       $v0, $v1, -0xA
    ctx->pc = 0x12ce08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967286));
    // 0x12ce0c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x12ce0cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x12ce10: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x12CE10u;
    {
        const bool branch_taken_0x12ce10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ce10) {
            ctx->pc = 0x12CE14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE10u;
            // 0x12ce14: 0x8e230000  lw          $v1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12CE30u;
            goto label_12ce30;
        }
    }
    ctx->pc = 0x12CE18u;
    // 0x12ce18: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x12ce18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x12ce1c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12CE1Cu;
    {
        const bool branch_taken_0x12ce1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x12CE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE1Cu;
            // 0x12ce20: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ce1c) {
            ctx->pc = 0x12CE2Cu;
            goto label_12ce2c;
        }
    }
    ctx->pc = 0x12CE24u;
    // 0x12ce24: 0x5462000a  bnel        $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x12CE24u;
    {
        const bool branch_taken_0x12ce24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12ce24) {
            ctx->pc = 0x12CE28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE24u;
            // 0x12ce28: 0x27b00010  addiu       $s0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12CE50u;
            goto label_12ce50;
        }
    }
    ctx->pc = 0x12CE2Cu;
label_12ce2c:
    // 0x12ce2c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12ce2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_12ce30:
    // 0x12ce30: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12ce30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce34: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12ce34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ce38: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12ce38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12ce3c: 0x40f809  jalr        $v0
    ctx->pc = 0x12CE3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12CE44u);
        ctx->pc = 0x12CE40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE3Cu;
            // 0x12ce40: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CE44u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CE44u; }
            if (ctx->pc != 0x12CE44u) { return; }
        }
        }
    }
    ctx->pc = 0x12CE44u;
label_12ce44:
    // 0x12ce44: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x12CE44u;
    {
        const bool branch_taken_0x12ce44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CE48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE44u;
            // 0x12ce48: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ce44) {
            ctx->pc = 0x12CE98u;
            goto label_12ce98;
        }
    }
    ctx->pc = 0x12CE4Cu;
    // 0x12ce4c: 0x0  nop
    ctx->pc = 0x12ce4cu;
    // NOP
label_12ce50:
    // 0x12ce50: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12ce50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce54: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12ce54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce58: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x12ce58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce5c: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x12CE5Cu;
    SET_GPR_U32(ctx, 31, 0x12CE64u);
    ctx->pc = 0x12CE60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE5Cu;
            // 0x12ce60: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CE64u; }
        if (ctx->pc != 0x12CE64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CE64u; }
        if (ctx->pc != 0x12CE64u) { return; }
    }
    ctx->pc = 0x12CE64u;
label_12ce64:
    // 0x12ce64: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12ce64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ce68: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12ce68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce6c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12ce6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce70: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12ce70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12ce74: 0x40f809  jalr        $v0
    ctx->pc = 0x12CE74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12CE7Cu);
        ctx->pc = 0x12CE78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE74u;
            // 0x12ce78: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CE7Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CE7Cu; }
            if (ctx->pc != 0x12CE7Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12CE7Cu;
label_12ce7c:
    // 0x12ce7c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12ce7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ce80: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12ce80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce84: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12ce84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ce88: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12ce88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12ce8c: 0x40f809  jalr        $v0
    ctx->pc = 0x12CE8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12CE94u);
        ctx->pc = 0x12CE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CE8Cu;
            // 0x12ce90: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CE94u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CE94u; }
            if (ctx->pc != 0x12CE94u) { return; }
        }
        }
    }
    ctx->pc = 0x12CE94u;
label_12ce94:
    // 0x12ce94: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12ce94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_12ce98:
    // 0x12ce98: 0xa2620001  sb          $v0, 0x1($s3)
    ctx->pc = 0x12ce98u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12ce9c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12ce9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_12cea0:
    // 0x12cea0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12cea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12cea4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12cea4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12cea8: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x12cea8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12ceac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12ceacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12ceb0: 0x3e00008  jr          $ra
    ctx->pc = 0x12CEB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CEB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CEB0u;
            // 0x12ceb4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CD20u: goto label_12cd20;
            case 0x12CD3Cu: goto label_12cd3c;
            case 0x12CD54u: goto label_12cd54;
            case 0x12CD58u: goto label_12cd58;
            case 0x12CD6Cu: goto label_12cd6c;
            case 0x12CD78u: goto label_12cd78;
            case 0x12CD98u: goto label_12cd98;
            case 0x12CDACu: goto label_12cdac;
            case 0x12CDB8u: goto label_12cdb8;
            case 0x12CDC0u: goto label_12cdc0;
            case 0x12CDD0u: goto label_12cdd0;
            case 0x12CDD8u: goto label_12cdd8;
            case 0x12CDFCu: goto label_12cdfc;
            case 0x12CE04u: goto label_12ce04;
            case 0x12CE2Cu: goto label_12ce2c;
            case 0x12CE30u: goto label_12ce30;
            case 0x12CE44u: goto label_12ce44;
            case 0x12CE50u: goto label_12ce50;
            case 0x12CE64u: goto label_12ce64;
            case 0x12CE7Cu: goto label_12ce7c;
            case 0x12CE94u: goto label_12ce94;
            case 0x12CE98u: goto label_12ce98;
            case 0x12CEA0u: goto label_12cea0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12CEB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
