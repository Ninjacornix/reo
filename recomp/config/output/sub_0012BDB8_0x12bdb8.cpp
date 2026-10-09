#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BDB8
// Address: 0x12bdb8 - 0x12bee0
void sub_0012BDB8_0x12bdb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BDB8_0x12bdb8");
#endif

    switch (ctx->pc) {
        case 0x12be2cu: goto label_12be2c;
        case 0x12be4cu: goto label_12be4c;
        case 0x12be54u: goto label_12be54;
        case 0x12be80u: goto label_12be80;
        case 0x12be9cu: goto label_12be9c;
        case 0x12bebcu: goto label_12bebc;
        default: break;
    }

    ctx->pc = 0x12bdb8u;

    // 0x12bdb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12bdb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12bdbc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12bdbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12bdc0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12bdc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12bdc4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12bdc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12bdc8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12bdc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12bdcc: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x12bdccu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x12bdd0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12bdd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12bdd4: 0x2442f3c4  addiu       $v0, $v0, -0xC3C
    ctx->pc = 0x12bdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964164));
    // 0x12bdd8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12bdd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12bddc: 0x2645055c  addiu       $a1, $s2, 0x55C
    ctx->pc = 0x12bddcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 1372));
    // 0x12bde0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12bde0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12bde4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x12bde4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12bde8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x12bde8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x12bdec: 0x8ca40000  lw          $a0, 0x0($a1)
    ctx->pc = 0x12bdecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12bdf0: 0x1480002d  bnez        $a0, . + 4 + (0x2D << 2)
    ctx->pc = 0x12BDF0u;
    {
        const bool branch_taken_0x12bdf0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12BDF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BDF0u;
            // 0x12bdf4: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bdf0) {
            ctx->pc = 0x12BEA8u;
            goto label_12bea8;
        }
    }
    ctx->pc = 0x12BDF8u;
    // 0x12bdf8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12bdf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12bdfc: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x12bdfcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12be00: 0x8c430454  lw          $v1, 0x454($v0)
    ctx->pc = 0x12be00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1108)));
    // 0x12be04: 0xacb00000  sw          $s0, 0x0($a1)
    ctx->pc = 0x12be04u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 16));
    // 0x12be08: 0x18600022  blez        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x12BE08u;
    {
        const bool branch_taken_0x12be08 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12BE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE08u;
            // 0x12be0c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12be08) {
            ctx->pc = 0x12BE94u;
            goto label_12be94;
        }
    }
    ctx->pc = 0x12BE10u;
    // 0x12be10: 0x24420488  addiu       $v0, $v0, 0x488
    ctx->pc = 0x12be10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1160));
    // 0x12be14: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12be14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12be18: 0x10700004  beq         $v1, $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12BE18u;
    {
        const bool branch_taken_0x12be18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 16));
        ctx->pc = 0x12BE1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE18u;
            // 0x12be1c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12be18) {
            ctx->pc = 0x12BE2Cu;
            goto label_12be2c;
        }
    }
    ctx->pc = 0x12BE20u;
    // 0x12be20: 0x244204e0  addiu       $v0, $v0, 0x4E0
    ctx->pc = 0x12be20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1248));
    // 0x12be24: 0xc04ac0e  jal         func_12B038
    ctx->pc = 0x12BE24u;
    SET_GPR_U32(ctx, 31, 0x12BE2Cu);
    ctx->pc = 0x12BE28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE24u;
            // 0x12be28: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B038u;
    if (runtime->hasFunction(0x12B038u)) {
        auto targetFn = runtime->lookupFunction(0x12B038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE2Cu; }
        if (ctx->pc != 0x12BE2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B038_0x12b038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE2Cu; }
        if (ctx->pc != 0x12BE2Cu) { return; }
    }
    ctx->pc = 0x12BE2Cu;
label_12be2c:
    // 0x12be2c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12be2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12be30: 0x24420490  addiu       $v0, $v0, 0x490
    ctx->pc = 0x12be30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1168));
    // 0x12be34: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12be34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12be38: 0x10700004  beq         $v1, $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12BE38u;
    {
        const bool branch_taken_0x12be38 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 16));
        ctx->pc = 0x12BE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE38u;
            // 0x12be3c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12be38) {
            ctx->pc = 0x12BE4Cu;
            goto label_12be4c;
        }
    }
    ctx->pc = 0x12BE40u;
    // 0x12be40: 0x244204e4  addiu       $v0, $v0, 0x4E4
    ctx->pc = 0x12be40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1252));
    // 0x12be44: 0xc04ac0e  jal         func_12B038
    ctx->pc = 0x12BE44u;
    SET_GPR_U32(ctx, 31, 0x12BE4Cu);
    ctx->pc = 0x12BE48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE44u;
            // 0x12be48: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B038u;
    if (runtime->hasFunction(0x12B038u)) {
        auto targetFn = runtime->lookupFunction(0x12B038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE4Cu; }
        if (ctx->pc != 0x12BE4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B038_0x12b038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE4Cu; }
        if (ctx->pc != 0x12BE4Cu) { return; }
    }
    ctx->pc = 0x12BE4Cu;
label_12be4c:
    // 0x12be4c: 0xc04ad4c  jal         func_12B530
    ctx->pc = 0x12BE4Cu;
    SET_GPR_U32(ctx, 31, 0x12BE54u);
    ctx->pc = 0x12B530u;
    if (runtime->hasFunction(0x12B530u)) {
        auto targetFn = runtime->lookupFunction(0x12B530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE54u; }
        if (ctx->pc != 0x12BE54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B530_0x12b530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE54u; }
        if (ctx->pc != 0x12BE54u) { return; }
    }
    ctx->pc = 0x12BE54u;
label_12be54:
    // 0x12be54: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12be54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12be58: 0x1490000a  bne         $a0, $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x12BE58u;
    {
        const bool branch_taken_0x12be58 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 16));
        ctx->pc = 0x12BE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE58u;
            // 0x12be5c: 0x3c030021  lui         $v1, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12be58) {
            ctx->pc = 0x12BE84u;
            goto label_12be84;
        }
    }
    ctx->pc = 0x12BE60u;
    // 0x12be60: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12be60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12be64: 0x2442048c  addiu       $v0, $v0, 0x48C
    ctx->pc = 0x12be64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1164));
    // 0x12be68: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12be68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12be6c: 0x10640004  beq         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12BE6Cu;
    {
        const bool branch_taken_0x12be6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x12BE70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE6Cu;
            // 0x12be70: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12be6c) {
            ctx->pc = 0x12BE80u;
            goto label_12be80;
        }
    }
    ctx->pc = 0x12BE74u;
    // 0x12be74: 0x244204dc  addiu       $v0, $v0, 0x4DC
    ctx->pc = 0x12be74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1244));
    // 0x12be78: 0xc04ac0e  jal         func_12B038
    ctx->pc = 0x12BE78u;
    SET_GPR_U32(ctx, 31, 0x12BE80u);
    ctx->pc = 0x12BE7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BE78u;
            // 0x12be7c: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B038u;
    if (runtime->hasFunction(0x12B038u)) {
        auto targetFn = runtime->lookupFunction(0x12B038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE80u; }
        if (ctx->pc != 0x12BE80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B038_0x12b038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE80u; }
        if (ctx->pc != 0x12BE80u) { return; }
    }
    ctx->pc = 0x12BE80u;
label_12be80:
    // 0x12be80: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12be80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
label_12be84:
    // 0x12be84: 0x246304d0  addiu       $v1, $v1, 0x4D0
    ctx->pc = 0x12be84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1232));
    // 0x12be88: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x12be88u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12be8c: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12be8cu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12be90: 0xfc620000  sd          $v0, 0x0($v1)
    ctx->pc = 0x12be90u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 2));
label_12be94:
    // 0x12be94: 0xc0507e4  jal         func_141F90
    ctx->pc = 0x12BE94u;
    SET_GPR_U32(ctx, 31, 0x12BE9Cu);
    ctx->pc = 0x141F90u;
    if (runtime->hasFunction(0x141F90u)) {
        auto targetFn = runtime->lookupFunction(0x141F90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE9Cu; }
        if (ctx->pc != 0x12BE9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141F90_0x141f90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12BE9Cu; }
        if (ctx->pc != 0x12BE9Cu) { return; }
    }
    ctx->pc = 0x12BE9Cu;
label_12be9c:
    // 0x12be9c: 0x2643055c  addiu       $v1, $s2, 0x55C
    ctx->pc = 0x12be9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1372));
    // 0x12bea0: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x12bea0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x12bea4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12bea4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
label_12bea8:
    // 0x12bea8: 0x8c420560  lw          $v0, 0x560($v0)
    ctx->pc = 0x12bea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1376)));
    // 0x12beac: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x12BEACu;
    {
        const bool branch_taken_0x12beac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12beac) {
            ctx->pc = 0x12BEB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12BEACu;
            // 0x12beb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12BEC8u;
            goto label_12bec8;
        }
    }
    ctx->pc = 0x12BEB4u;
    // 0x12beb4: 0x40f809  jalr        $v0
    ctx->pc = 0x12BEB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12BEBCu);
        ctx->pc = 0x12BEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BEB4u;
            // 0x12beb8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12BEBCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BE2Cu: goto label_12be2c;
            case 0x12BE4Cu: goto label_12be4c;
            case 0x12BE54u: goto label_12be54;
            case 0x12BE80u: goto label_12be80;
            case 0x12BE84u: goto label_12be84;
            case 0x12BE94u: goto label_12be94;
            case 0x12BE9Cu: goto label_12be9c;
            case 0x12BEA8u: goto label_12bea8;
            case 0x12BEBCu: goto label_12bebc;
            case 0x12BEC8u: goto label_12bec8;
            case 0x12BECCu: goto label_12becc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12BEBCu; }
            if (ctx->pc != 0x12BEBCu) { return; }
        }
        }
    }
    ctx->pc = 0x12BEBCu;
label_12bebc:
    // 0x12bebc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12BEBCu;
    {
        const bool branch_taken_0x12bebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12BEC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BEBCu;
            // 0x12bec0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12bebc) {
            ctx->pc = 0x12BECCu;
            goto label_12becc;
        }
    }
    ctx->pc = 0x12BEC4u;
    // 0x12bec4: 0x0  nop
    ctx->pc = 0x12bec4u;
    // NOP
label_12bec8:
    // 0x12bec8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12bec8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12becc:
    // 0x12becc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12beccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12bed0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12bed0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12bed4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12bed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12bed8: 0x3e00008  jr          $ra
    ctx->pc = 0x12BED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12BEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12BED8u;
            // 0x12bedc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12BE2Cu: goto label_12be2c;
            case 0x12BE4Cu: goto label_12be4c;
            case 0x12BE54u: goto label_12be54;
            case 0x12BE80u: goto label_12be80;
            case 0x12BE84u: goto label_12be84;
            case 0x12BE94u: goto label_12be94;
            case 0x12BE9Cu: goto label_12be9c;
            case 0x12BEA8u: goto label_12bea8;
            case 0x12BEBCu: goto label_12bebc;
            case 0x12BEC8u: goto label_12bec8;
            case 0x12BECCu: goto label_12becc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12BEE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
