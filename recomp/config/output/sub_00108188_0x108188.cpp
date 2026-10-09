#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108188
// Address: 0x108188 - 0x108248
void sub_00108188_0x108188(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108188_0x108188");
#endif

    ctx->pc = 0x108188u;

    // 0x108188: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x108188u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10818c: 0x30a20007  andi        $v0, $a1, 0x7
    ctx->pc = 0x10818cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)7);
    // 0x108190: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x108190u;
    {
        const bool branch_taken_0x108190 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x108194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108190u;
            // 0x108194: 0x30a30001  andi        $v1, $a1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x108190) {
            ctx->pc = 0x1081C8u;
            goto label_1081c8;
        }
    }
    ctx->pc = 0x108198u;
    // 0x108198: 0x14600028  bnez        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x108198u;
    {
        const bool branch_taken_0x108198 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10819Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108198u;
            // 0x10819c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108198) {
            ctx->pc = 0x10823Cu;
            goto label_10823c;
        }
    }
    ctx->pc = 0x1081A0u;
    // 0x1081a0: 0x30a20002  andi        $v0, $a1, 0x2
    ctx->pc = 0x1081a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
    // 0x1081a4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1081A4u;
    {
        const bool branch_taken_0x1081a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1081A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1081A4u;
            // 0x1081a8: 0x51842  srl         $v1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1081a4) {
            ctx->pc = 0x1081B8u;
            goto label_1081b8;
        }
    }
    ctx->pc = 0x1081ACu;
    // 0x1081ac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1081acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1081b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1081B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1081B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1081B0u;
            // 0x1081b4: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1081B8u: goto label_1081b8;
            case 0x1081C8u: goto label_1081c8;
            case 0x1081DCu: goto label_1081dc;
            case 0x1081F4u: goto label_1081f4;
            case 0x108208u: goto label_108208;
            case 0x10821Cu: goto label_10821c;
            case 0x108238u: goto label_108238;
            case 0x10823Cu: goto label_10823c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1081B8u;
label_1081b8:
    // 0x1081b8: 0x51882  srl         $v1, $a1, 2
    ctx->pc = 0x1081b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 2));
    // 0x1081bc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1081bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1081c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1081C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1081C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1081C0u;
            // 0x1081c4: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1081B8u: goto label_1081b8;
            case 0x1081C8u: goto label_1081c8;
            case 0x1081DCu: goto label_1081dc;
            case 0x1081F4u: goto label_1081f4;
            case 0x108208u: goto label_108208;
            case 0x10821Cu: goto label_10821c;
            case 0x108238u: goto label_108238;
            case 0x10823Cu: goto label_10823c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1081C8u;
label_1081c8:
    // 0x1081c8: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x1081c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1081cc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1081CCu;
    {
        const bool branch_taken_0x1081cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1081D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1081CCu;
            // 0x1081d0: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1081cc) {
            ctx->pc = 0x1081DCu;
            goto label_1081dc;
        }
    }
    ctx->pc = 0x1081D4u;
    // 0x1081d4: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1081d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1081d8: 0x52c02  srl         $a1, $a1, 16
    ctx->pc = 0x1081d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
label_1081dc:
    // 0x1081dc: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1081dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1081e0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1081E0u;
    {
        const bool branch_taken_0x1081e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1081E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1081E0u;
            // 0x1081e4: 0x30a2000f  andi        $v0, $a1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1081e0) {
            ctx->pc = 0x1081F4u;
            goto label_1081f4;
        }
    }
    ctx->pc = 0x1081E8u;
    // 0x1081e8: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1081e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1081ec: 0x52a02  srl         $a1, $a1, 8
    ctx->pc = 0x1081ecu;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
    // 0x1081f0: 0x30a2000f  andi        $v0, $a1, 0xF
    ctx->pc = 0x1081f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)15);
label_1081f4:
    // 0x1081f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1081F4u;
    {
        const bool branch_taken_0x1081f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1081F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1081F4u;
            // 0x1081f8: 0x30a20003  andi        $v0, $a1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1081f4) {
            ctx->pc = 0x108208u;
            goto label_108208;
        }
    }
    ctx->pc = 0x1081FCu;
    // 0x1081fc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1081fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x108200: 0x52902  srl         $a1, $a1, 4
    ctx->pc = 0x108200u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 4));
    // 0x108204: 0x30a20003  andi        $v0, $a1, 0x3
    ctx->pc = 0x108204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)3);
label_108208:
    // 0x108208: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x108208u;
    {
        const bool branch_taken_0x108208 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10820Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108208u;
            // 0x10820c: 0x30a20001  andi        $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x108208) {
            ctx->pc = 0x10821Cu;
            goto label_10821c;
        }
    }
    ctx->pc = 0x108210u;
    // 0x108210: 0x24630002  addiu       $v1, $v1, 0x2
    ctx->pc = 0x108210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x108214: 0x52882  srl         $a1, $a1, 2
    ctx->pc = 0x108214u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 2));
    // 0x108218: 0x30a20001  andi        $v0, $a1, 0x1
    ctx->pc = 0x108218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
label_10821c:
    // 0x10821c: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10821Cu;
    {
        const bool branch_taken_0x10821c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10821c) {
            ctx->pc = 0x108220u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10821Cu;
            // 0x108220: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108238u;
            goto label_108238;
        }
    }
    ctx->pc = 0x108224u;
    // 0x108224: 0x52842  srl         $a1, $a1, 1
    ctx->pc = 0x108224u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 1));
    // 0x108228: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x108228u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10822c: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x10822Cu;
    {
        const bool branch_taken_0x10822c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x108230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10822Cu;
            // 0x108230: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10822c) {
            ctx->pc = 0x10823Cu;
            goto label_10823c;
        }
    }
    ctx->pc = 0x108234u;
    // 0x108234: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x108234u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
label_108238:
    // 0x108238: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x108238u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10823c:
    // 0x10823c: 0x3e00008  jr          $ra
    ctx->pc = 0x10823Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1081B8u: goto label_1081b8;
            case 0x1081C8u: goto label_1081c8;
            case 0x1081DCu: goto label_1081dc;
            case 0x1081F4u: goto label_1081f4;
            case 0x108208u: goto label_108208;
            case 0x10821Cu: goto label_10821c;
            case 0x108238u: goto label_108238;
            case 0x10823Cu: goto label_10823c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108244u;
    // 0x108244: 0x0  nop
    ctx->pc = 0x108244u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
