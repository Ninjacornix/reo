#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1130
// Address: 0x1c1130 - 0x1c125c
void sub_001C1130_0x1c1130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1130_0x1c1130");
#endif

    switch (ctx->pc) {
        case 0x1c1164u: goto label_1c1164;
        case 0x1c11c4u: goto label_1c11c4;
        case 0x1c124cu: goto label_1c124c;
        default: break;
    }

    ctx->pc = 0x1c1130u;

    // 0x1c1130: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c1134: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c1134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1138: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c1138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c113c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c113cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1140: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c1140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c1144: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C1144u;
    {
        const bool branch_taken_0x1c1144 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C1148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1144u;
            // 0x1c1148: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1144) {
            ctx->pc = 0x1C11BCu;
            goto label_1c11bc;
        }
    }
    ctx->pc = 0x1C114Cu;
    // 0x1c114c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C114Cu;
    {
        const bool branch_taken_0x1c114c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c114c) {
            ctx->pc = 0x1C115Cu;
            goto label_1c115c;
        }
    }
    ctx->pc = 0x1C1154u;
    // 0x1c1154: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1C1154u;
    {
        const bool branch_taken_0x1c1154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1154u;
            // 0x1c1158: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1154) {
            ctx->pc = 0x1C1244u;
            goto label_1c1244;
        }
    }
    ctx->pc = 0x1C115Cu;
label_1c115c:
    // 0x1c115c: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C115Cu;
    SET_GPR_U32(ctx, 31, 0x1C1164u);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1164u; }
        if (ctx->pc != 0x1C1164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1164u; }
        if (ctx->pc != 0x1C1164u) { return; }
    }
    ctx->pc = 0x1C1164u;
label_1c1164:
    // 0x1c1164: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c1164u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c1168: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C1168u;
    {
        const bool branch_taken_0x1c1168 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C116Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1168u;
            // 0x1c116c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1168) {
            ctx->pc = 0x1C11ACu;
            goto label_1c11ac;
        }
    }
    ctx->pc = 0x1C1170u;
    // 0x1c1170: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C1170u;
    {
        const bool branch_taken_0x1c1170 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c1170) {
            ctx->pc = 0x1C11ACu;
            goto label_1c11ac;
        }
    }
    ctx->pc = 0x1C1178u;
    // 0x1c1178: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c1178u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c117c: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C117Cu;
    {
        const bool branch_taken_0x1c117c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c117c) {
            ctx->pc = 0x1C11A0u;
            goto label_1c11a0;
        }
    }
    ctx->pc = 0x1C1184u;
    // 0x1c1184: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1184u;
    {
        const bool branch_taken_0x1c1184 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1184) {
            ctx->pc = 0x1C1194u;
            goto label_1c1194;
        }
    }
    ctx->pc = 0x1C118Cu;
    // 0x1c118c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1C118Cu;
    {
        const bool branch_taken_0x1c118c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c118c) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C1194u;
label_1c1194:
    // 0x1c1194: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c1194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c1198: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1C1198u;
    {
        const bool branch_taken_0x1c1198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C119Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1198u;
            // 0x1c119c: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1198) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11A0u;
label_1c11a0:
    // 0x1c11a0: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c11a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c11a4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1C11A4u;
    {
        const bool branch_taken_0x1c11a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C11A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11A4u;
            // 0x1c11a8: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11a4) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11ACu;
label_1c11ac:
    // 0x1c11ac: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1c11acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c11b0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c11b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c11b4: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C11B4u;
    {
        const bool branch_taken_0x1c11b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C11B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11B4u;
            // 0x1c11b8: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11b4) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11BCu;
label_1c11bc:
    // 0x1c11bc: 0xc0700a8  jal         func_1C02A0
    ctx->pc = 0x1C11BCu;
    SET_GPR_U32(ctx, 31, 0x1C11C4u);
    ctx->pc = 0x1C02A0u;
    if (runtime->hasFunction(0x1C02A0u)) {
        auto targetFn = runtime->lookupFunction(0x1C02A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C11C4u; }
        if (ctx->pc != 0x1C11C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C02A0_0x1c02a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C11C4u; }
        if (ctx->pc != 0x1C11C4u) { return; }
    }
    ctx->pc = 0x1C11C4u;
label_1c11c4:
    // 0x1c11c4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c11c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c11c8: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C11C8u;
    {
        const bool branch_taken_0x1c11c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c11c8) {
            ctx->pc = 0x1C11F0u;
            goto label_1c11f0;
        }
    }
    ctx->pc = 0x1C11D0u;
    // 0x1c11d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C11D0u;
    {
        const bool branch_taken_0x1c11d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c11d0) {
            ctx->pc = 0x1C11E0u;
            goto label_1c11e0;
        }
    }
    ctx->pc = 0x1C11D8u;
    // 0x1c11d8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1C11D8u;
    {
        const bool branch_taken_0x1c11d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c11d8) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11E0u;
label_1c11e0:
    // 0x1c11e0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c11e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c11e4: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1c11e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c11e8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1C11E8u;
    {
        const bool branch_taken_0x1c11e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C11ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11E8u;
            // 0x1c11ec: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11e8) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C11F0u;
label_1c11f0:
    // 0x1c11f0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1c11f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1c11f4: 0x34029002  ori         $v0, $zero, 0x9002
    ctx->pc = 0x1c11f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36866);
    // 0x1c11f8: 0x9603001c  lhu         $v1, 0x1C($s0)
    ctx->pc = 0x1c11f8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c11fc: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C11FCu;
    {
        const bool branch_taken_0x1c11fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C1200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C11FCu;
            // 0x1c1200: 0x2402ff05  addiu       $v0, $zero, -0xFB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c11fc) {
            ctx->pc = 0x1C1234u;
            goto label_1c1234;
        }
    }
    ctx->pc = 0x1C1204u;
    // 0x1c1204: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c1204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c1208: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C1208u;
    {
        const bool branch_taken_0x1c1208 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C120Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1208u;
            // 0x1c120c: 0x2402ff03  addiu       $v0, $zero, -0xFD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1208) {
            ctx->pc = 0x1C122Cu;
            goto label_1c122c;
        }
    }
    ctx->pc = 0x1C1210u;
    // 0x1c1210: 0x24020013  addiu       $v0, $zero, 0x13
    ctx->pc = 0x1c1210u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1c1214: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1214u;
    {
        const bool branch_taken_0x1c1214 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C1218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1214u;
            // 0x1c1218: 0x2402ff01  addiu       $v0, $zero, -0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1214) {
            ctx->pc = 0x1C1224u;
            goto label_1c1224;
        }
    }
    ctx->pc = 0x1C121Cu;
    // 0x1c121c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C121Cu;
    {
        const bool branch_taken_0x1c121c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C121Cu;
            // 0x1c1220: 0x2402ff00  addiu       $v0, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c121c) {
            ctx->pc = 0x1C123Cu;
            goto label_1c123c;
        }
    }
    ctx->pc = 0x1C1224u;
label_1c1224:
    // 0x1c1224: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C1224u;
    {
        const bool branch_taken_0x1c1224 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1224u;
            // 0x1c1228: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1224) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C122Cu;
label_1c122c:
    // 0x1c122c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C122Cu;
    {
        const bool branch_taken_0x1c122c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C122Cu;
            // 0x1c1230: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c122c) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C1234u;
label_1c1234:
    // 0x1c1234: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1234u;
    {
        const bool branch_taken_0x1c1234 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1234u;
            // 0x1c1238: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1234) {
            ctx->pc = 0x1C1240u;
            goto label_1c1240;
        }
    }
    ctx->pc = 0x1C123Cu;
label_1c123c:
    // 0x1c123c: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1c123cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
label_1c1240:
    // 0x1c1240: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c1240u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c1244:
    // 0x1c1244: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C1244u;
    SET_GPR_U32(ctx, 31, 0x1C124Cu);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C124Cu; }
        if (ctx->pc != 0x1C124Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C124Cu; }
        if (ctx->pc != 0x1C124Cu) { return; }
    }
    ctx->pc = 0x1C124Cu;
label_1c124c:
    // 0x1c124c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c124cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1250: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1250u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1254: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1254u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1254u;
            // 0x1c1258: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C115Cu: goto label_1c115c;
            case 0x1C1164u: goto label_1c1164;
            case 0x1C1194u: goto label_1c1194;
            case 0x1C11A0u: goto label_1c11a0;
            case 0x1C11ACu: goto label_1c11ac;
            case 0x1C11BCu: goto label_1c11bc;
            case 0x1C11C4u: goto label_1c11c4;
            case 0x1C11E0u: goto label_1c11e0;
            case 0x1C11F0u: goto label_1c11f0;
            case 0x1C1224u: goto label_1c1224;
            case 0x1C122Cu: goto label_1c122c;
            case 0x1C1234u: goto label_1c1234;
            case 0x1C123Cu: goto label_1c123c;
            case 0x1C1240u: goto label_1c1240;
            case 0x1C1244u: goto label_1c1244;
            case 0x1C124Cu: goto label_1c124c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C125Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
