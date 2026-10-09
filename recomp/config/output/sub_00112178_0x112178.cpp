#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112178
// Address: 0x112178 - 0x112298
void sub_00112178_0x112178(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112178_0x112178");
#endif

    ctx->pc = 0x112178u;

    // 0x112178: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x112178u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x11217c: 0x2cc20002  sltiu       $v0, $a2, 0x2
    ctx->pc = 0x11217cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x112180: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x112180u;
    {
        const bool branch_taken_0x112180 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x112180) {
            ctx->pc = 0x112198u;
            goto label_112198;
        }
    }
    ctx->pc = 0x112188u;
    // 0x112188: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x112188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11218c: 0x2c620002  sltiu       $v0, $v1, 0x2
    ctx->pc = 0x11218cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x112190: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x112190u;
    {
        const bool branch_taken_0x112190 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x112190) {
            ctx->pc = 0x112194u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112190u;
            // 0x112194: 0x38c20004  xori        $v0, $a2, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1121A0u;
            goto label_1121a0;
        }
    }
    ctx->pc = 0x112198u;
label_112198:
    // 0x112198: 0x3e00008  jr          $ra
    ctx->pc = 0x112198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11219Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112198u;
            // 0x11219c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1121A0u;
label_1121a0:
    // 0x1121a0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1121A0u;
    {
        const bool branch_taken_0x1121a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1121A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1121A0u;
            // 0x1121a4: 0x38620004  xori        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1121a0) {
            ctx->pc = 0x1121C0u;
            goto label_1121c0;
        }
    }
    ctx->pc = 0x1121A8u;
    // 0x1121a8: 0x5440001a  bnel        $v0, $zero, . + 4 + (0x1A << 2)
    ctx->pc = 0x1121A8u;
    {
        const bool branch_taken_0x1121a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1121a8) {
            ctx->pc = 0x1121ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1121A8u;
            // 0x1121ac: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x112214u;
            goto label_112214;
        }
    }
    ctx->pc = 0x1121B0u;
    // 0x1121b0: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x1121b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1121b4: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1121b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1121b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1121B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1121BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1121B8u;
            // 0x1121bc: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1121C0u;
label_1121c0:
    // 0x1121c0: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1121C0u;
    {
        const bool branch_taken_0x1121c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1121c0) {
            ctx->pc = 0x1121C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1121C0u;
            // 0x1121c4: 0x38c20002  xori        $v0, $a2, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1121E0u;
            goto label_1121e0;
        }
    }
    ctx->pc = 0x1121C8u;
    // 0x1121c8: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x1121c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1121cc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1121ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1121d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1121d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1121d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1121D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1121D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1121D4u;
            // 0x1121d8: 0x64100a  movz        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1121DCu;
    // 0x1121dc: 0x0  nop
    ctx->pc = 0x1121dcu;
    // NOP
label_1121e0:
    // 0x1121e0: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1121E0u;
    {
        const bool branch_taken_0x1121e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1121e0) {
            ctx->pc = 0x1121E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1121E0u;
            // 0x1121e4: 0x38620002  xori        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
            ctx->pc = 0x112208u;
            goto label_112208;
        }
    }
    ctx->pc = 0x1121E8u;
    // 0x1121e8: 0x38630002  xori        $v1, $v1, 0x2
    ctx->pc = 0x1121e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x1121ec: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1121ECu;
    {
        const bool branch_taken_0x1121ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1121F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1121ECu;
            // 0x1121f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1121ec) {
            ctx->pc = 0x112290u;
            goto label_112290;
        }
    }
    ctx->pc = 0x1121F4u;
    // 0x1121f4: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x1121f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1121f8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1121f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1121fc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1121fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x112200: 0x3e00008  jr          $ra
    ctx->pc = 0x112200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112200u;
            // 0x112204: 0x64100b  movn        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112208u;
label_112208:
    // 0x112208: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x112208u;
    {
        const bool branch_taken_0x112208 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x112208) {
            ctx->pc = 0x11220Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112208u;
            // 0x11220c: 0x8c870004  lw          $a3, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x112228u;
            goto label_112228;
        }
    }
    ctx->pc = 0x112210u;
    // 0x112210: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x112210u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
label_112214:
    // 0x112214: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x112214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112218: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x112218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11221c: 0x3e00008  jr          $ra
    ctx->pc = 0x11221Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11221Cu;
            // 0x112220: 0x64100a  movz        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112224u;
    // 0x112224: 0x0  nop
    ctx->pc = 0x112224u;
    // NOP
label_112228:
    // 0x112228: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x112228u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x11222c: 0x14e2000f  bne         $a3, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x11222Cu;
    {
        const bool branch_taken_0x11222c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x112230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11222Cu;
            // 0x112230: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11222c) {
            ctx->pc = 0x11226Cu;
            goto label_11226c;
        }
    }
    ctx->pc = 0x112234u;
    // 0x112234: 0x8c860008  lw          $a2, 0x8($a0)
    ctx->pc = 0x112234u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x112238: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x112238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x11223c: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x11223cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x112240: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x112240u;
    {
        const bool branch_taken_0x112240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x112240) {
            ctx->pc = 0x112244u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112240u;
            // 0x112244: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11226Cu;
            goto label_11226c;
        }
    }
    ctx->pc = 0x112248u;
    // 0x112248: 0xc3102a  slt         $v0, $a2, $v1
    ctx->pc = 0x112248u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x11224c: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11224Cu;
    {
        const bool branch_taken_0x11224c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x112250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11224Cu;
            // 0x112250: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11224c) {
            ctx->pc = 0x112284u;
            goto label_112284;
        }
    }
    ctx->pc = 0x112254u;
    // 0x112254: 0xdc830010  ld          $v1, 0x10($a0)
    ctx->pc = 0x112254u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x112258: 0xdca40010  ld          $a0, 0x10($a1)
    ctx->pc = 0x112258u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x11225c: 0x83102b  sltu        $v0, $a0, $v1
    ctx->pc = 0x11225cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x112260: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x112260u;
    {
        const bool branch_taken_0x112260 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x112260) {
            ctx->pc = 0x112264u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112260u;
            // 0x112264: 0x64102b  sltu        $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x112278u;
            goto label_112278;
        }
    }
    ctx->pc = 0x112268u;
    // 0x112268: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x112268u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11226c:
    // 0x11226c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11226cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x112270: 0x3e00008  jr          $ra
    ctx->pc = 0x112270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112270u;
            // 0x112274: 0x67100a  movz        $v0, $v1, $a3 (Delay Slot)
        if (GPR_U64(ctx, 7) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112278u;
label_112278:
    // 0x112278: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x112278u;
    {
        const bool branch_taken_0x112278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x112278) {
            ctx->pc = 0x11227Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x112278u;
            // 0x11227c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x112290u;
            goto label_112290;
        }
    }
    ctx->pc = 0x112280u;
    // 0x112280: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x112280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_112284:
    // 0x112284: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x112284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112288: 0x3e00008  jr          $ra
    ctx->pc = 0x112288u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11228Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112288u;
            // 0x11228c: 0x67100a  movz        $v0, $v1, $a3 (Delay Slot)
        if (GPR_U64(ctx, 7) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112290u;
label_112290:
    // 0x112290: 0x3e00008  jr          $ra
    ctx->pc = 0x112290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112198u: goto label_112198;
            case 0x1121A0u: goto label_1121a0;
            case 0x1121C0u: goto label_1121c0;
            case 0x1121E0u: goto label_1121e0;
            case 0x112208u: goto label_112208;
            case 0x112214u: goto label_112214;
            case 0x112228u: goto label_112228;
            case 0x11226Cu: goto label_11226c;
            case 0x112278u: goto label_112278;
            case 0x112284u: goto label_112284;
            case 0x112290u: goto label_112290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112298u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
