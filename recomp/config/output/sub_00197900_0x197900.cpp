#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00197900
// Address: 0x197900 - 0x197bb0
void sub_00197900_0x197900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00197900_0x197900");
#endif

    switch (ctx->pc) {
        case 0x197a94u: goto label_197a94;
        case 0x197aa8u: goto label_197aa8;
        case 0x197b98u: goto label_197b98;
        default: break;
    }

    ctx->pc = 0x197900u;

    // 0x197900: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x197900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x197904: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197904u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197908: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x197908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19790c: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x19790cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x197910: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x197910u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x197914: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x197914u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x197918: 0x8c27fe20  lw          $a3, -0x1E0($at)
    ctx->pc = 0x197918u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966816)));
    // 0x19791c: 0x14e20003  bne         $a3, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19791Cu;
    {
        const bool branch_taken_0x19791c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x197920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19791Cu;
            // 0x197920: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19791c) {
            ctx->pc = 0x19792Cu;
            goto label_19792c;
        }
    }
    ctx->pc = 0x197924u;
    // 0x197924: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x197924u;
    {
        const bool branch_taken_0x197924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197924u;
            // 0x197928: 0x24070080  addiu       $a3, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197924) {
            ctx->pc = 0x197944u;
            goto label_197944;
        }
    }
    ctx->pc = 0x19792Cu;
label_19792c:
    // 0x19792c: 0x10e00006  beqz        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x19792Cu;
    {
        const bool branch_taken_0x19792c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x197930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19792Cu;
            // 0x197930: 0x3c050038  lui         $a1, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)56 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19792c) {
            ctx->pc = 0x197948u;
            goto label_197948;
        }
    }
    ctx->pc = 0x197934u;
    // 0x197934: 0x73843  sra         $a3, $a3, 1
    ctx->pc = 0x197934u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 1));
    // 0x197938: 0x14e00002  bnez        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x197938u;
    {
        const bool branch_taken_0x197938 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x197938) {
            ctx->pc = 0x197944u;
            goto label_197944;
        }
    }
    ctx->pc = 0x197940u;
    // 0x197940: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x197940u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_197944:
    // 0x197944: 0x3c050038  lui         $a1, 0x38
    ctx->pc = 0x197944u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)56 << 16));
label_197948:
    // 0x197948: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x197948u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x19794c: 0x851824  and         $v1, $a0, $a1
    ctx->pc = 0x19794cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x197950: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x197950u;
    {
        const bool branch_taken_0x197950 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x197954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197950u;
            // 0x197954: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197950) {
            ctx->pc = 0x1979C8u;
            goto label_1979c8;
        }
    }
    ctx->pc = 0x197958u;
    // 0x197958: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x197958u;
    {
        const bool branch_taken_0x197958 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x197958) {
            ctx->pc = 0x1979C0u;
            goto label_1979c0;
        }
    }
    ctx->pc = 0x197960u;
    // 0x197960: 0x3c020030  lui         $v0, 0x30
    ctx->pc = 0x197960u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48 << 16));
    // 0x197964: 0x10620014  beq         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x197964u;
    {
        const bool branch_taken_0x197964 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x197968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197964u;
            // 0x197968: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197964) {
            ctx->pc = 0x1979B8u;
            goto label_1979b8;
        }
    }
    ctx->pc = 0x19796Cu;
    // 0x19796c: 0x10620010  beq         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x19796Cu;
    {
        const bool branch_taken_0x19796c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x19796c) {
            ctx->pc = 0x1979B0u;
            goto label_1979b0;
        }
    }
    ctx->pc = 0x197974u;
    // 0x197974: 0x3c020018  lui         $v0, 0x18
    ctx->pc = 0x197974u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24 << 16));
    // 0x197978: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x197978u;
    {
        const bool branch_taken_0x197978 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x19797Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197978u;
            // 0x19797c: 0x3c020008  lui         $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197978) {
            ctx->pc = 0x1979A8u;
            goto label_1979a8;
        }
    }
    ctx->pc = 0x197980u;
    // 0x197980: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x197980u;
    {
        const bool branch_taken_0x197980 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x197980) {
            ctx->pc = 0x1979A0u;
            goto label_1979a0;
        }
    }
    ctx->pc = 0x197988u;
    // 0x197988: 0x10650003  beq         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197988u;
    {
        const bool branch_taken_0x197988 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x197988) {
            ctx->pc = 0x197998u;
            goto label_197998;
        }
    }
    ctx->pc = 0x197990u;
    // 0x197990: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x197990u;
    {
        const bool branch_taken_0x197990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197990u;
            // 0x197994: 0x3400a  movz        $t0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197990) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x197998u;
label_197998:
    // 0x197998: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x197998u;
    {
        const bool branch_taken_0x197998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19799Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197998u;
            // 0x19799c: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197998) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979A0u;
label_1979a0:
    // 0x1979a0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1979A0u;
    {
        const bool branch_taken_0x1979a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1979A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979A0u;
            // 0x1979a4: 0x24080002  addiu       $t0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979a0) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979A8u;
label_1979a8:
    // 0x1979a8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1979A8u;
    {
        const bool branch_taken_0x1979a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1979ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979A8u;
            // 0x1979ac: 0x24080003  addiu       $t0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979a8) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979B0u;
label_1979b0:
    // 0x1979b0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1979B0u;
    {
        const bool branch_taken_0x1979b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1979B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979B0u;
            // 0x1979b4: 0x24080004  addiu       $t0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979b0) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979B8u;
label_1979b8:
    // 0x1979b8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1979B8u;
    {
        const bool branch_taken_0x1979b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1979BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979B8u;
            // 0x1979bc: 0x24080005  addiu       $t0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979b8) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979C0u;
label_1979c0:
    // 0x1979c0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1979C0u;
    {
        const bool branch_taken_0x1979c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1979C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979C0u;
            // 0x1979c4: 0x24080006  addiu       $t0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979c0) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979C8u;
label_1979c8:
    // 0x1979c8: 0x24080007  addiu       $t0, $zero, 0x7
    ctx->pc = 0x1979c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_1979cc:
    // 0x1979cc: 0x30837000  andi        $v1, $a0, 0x7000
    ctx->pc = 0x1979ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)28672);
    // 0x1979d0: 0x24026000  addiu       $v0, $zero, 0x6000
    ctx->pc = 0x1979d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24576));
    // 0x1979d4: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1979D4u;
    {
        const bool branch_taken_0x1979d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1979D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979D4u;
            // 0x1979d8: 0x24024000  addiu       $v0, $zero, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979d4) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979DCu;
    // 0x1979dc: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1979DCu;
    {
        const bool branch_taken_0x1979dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1979dc) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979E4u;
    // 0x1979e4: 0x24025000  addiu       $v0, $zero, 0x5000
    ctx->pc = 0x1979e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20480));
    // 0x1979e8: 0x10620016  beq         $v1, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1979E8u;
    {
        const bool branch_taken_0x1979e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1979ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979E8u;
            // 0x1979ec: 0x24022000  addiu       $v0, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979e8) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979F0u;
    // 0x1979f0: 0x10620014  beq         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1979F0u;
    {
        const bool branch_taken_0x1979f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1979f0) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979F8u;
    // 0x1979f8: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1979F8u;
    {
        const bool branch_taken_0x1979f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1979FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1979F8u;
            // 0x1979fc: 0x24027000  addiu       $v0, $zero, 0x7000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1979f8) {
            ctx->pc = 0x197A3Cu;
            goto label_197a3c;
        }
    }
    ctx->pc = 0x197A00u;
    // 0x197a00: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x197A00u;
    {
        const bool branch_taken_0x197a00 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x197a00) {
            ctx->pc = 0x197A34u;
            goto label_197a34;
        }
    }
    ctx->pc = 0x197A08u;
    // 0x197a08: 0x24023000  addiu       $v0, $zero, 0x3000
    ctx->pc = 0x197a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12288));
    // 0x197a0c: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x197A0Cu;
    {
        const bool branch_taken_0x197a0c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x197A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A0Cu;
            // 0x197a10: 0x24021000  addiu       $v0, $zero, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a0c) {
            ctx->pc = 0x197A2Cu;
            goto label_197a2c;
        }
    }
    ctx->pc = 0x197A14u;
    // 0x197a14: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x197A14u;
    {
        const bool branch_taken_0x197a14 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x197a14) {
            ctx->pc = 0x197A24u;
            goto label_197a24;
        }
    }
    ctx->pc = 0x197A1Cu;
    // 0x197a1c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x197A1Cu;
    {
        const bool branch_taken_0x197a1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A1Cu;
            // 0x197a20: 0x7183c  dsll32      $v1, $a3, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a1c) {
            ctx->pc = 0x197A4Cu;
            goto label_197a4c;
        }
    }
    ctx->pc = 0x197A24u;
label_197a24:
    // 0x197a24: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x197A24u;
    {
        const bool branch_taken_0x197a24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A24u;
            // 0x197a28: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a24) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A2Cu;
label_197a2c:
    // 0x197a2c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x197A2Cu;
    {
        const bool branch_taken_0x197a2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A2Cu;
            // 0x197a30: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a2c) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A34u;
label_197a34:
    // 0x197a34: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x197A34u;
    {
        const bool branch_taken_0x197a34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A34u;
            // 0x197a38: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a34) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A3Cu;
label_197a3c:
    // 0x197a3c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x197A3Cu;
    {
        const bool branch_taken_0x197a3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A3Cu;
            // 0x197a40: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a3c) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A44u;
label_197a44:
    // 0x197a44: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x197a44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_197a48:
    // 0x197a48: 0x7183c  dsll32      $v1, $a3, 0
    ctx->pc = 0x197a48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
label_197a4c:
    // 0x197a4c: 0x8103c  dsll32      $v0, $t0, 0
    ctx->pc = 0x197a4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) << (32 + 0));
    // 0x197a50: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x197a50u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x197a54: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x197a54u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x197a58: 0x32138  dsll        $a0, $v1, 4
    ctx->pc = 0x197a58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 4);
    // 0x197a5c: 0x21078  dsll        $v0, $v0, 1
    ctx->pc = 0x197a5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 1);
    // 0x197a60: 0x34430001  ori         $v1, $v0, 0x1
    ctx->pc = 0x197a60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x197a64: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x197a64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x197a68: 0x832825  or          $a1, $a0, $v1
    ctx->pc = 0x197a68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x197a6c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x197a6cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x197a70: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x197a70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x197a74: 0x21c78  dsll        $v1, $v0, 17
    ctx->pc = 0x197a74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 17);
    // 0x197a78: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x197a78u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x197a7c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x197a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x197a80: 0x12220006  beq         $s1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x197A80u;
    {
        const bool branch_taken_0x197a80 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x197A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A80u;
            // 0x197a84: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a80) {
            ctx->pc = 0x197A9Cu;
            goto label_197a9c;
        }
    }
    ctx->pc = 0x197A88u;
    // 0x197a88: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x197a88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x197a8c: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x197A8Cu;
    SET_GPR_U32(ctx, 31, 0x197A94u);
    ctx->pc = 0x197A90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197A8Cu;
            // 0x197a90: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197A94u; }
        if (ctx->pc != 0x197A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197A94u; }
        if (ctx->pc != 0x197A94u) { return; }
    }
    ctx->pc = 0x197A94u;
label_197a94:
    // 0x197a94: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x197A94u;
    {
        const bool branch_taken_0x197a94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197A94u;
            // 0x197a98: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197a94) {
            ctx->pc = 0x197AACu;
            goto label_197aac;
        }
    }
    ctx->pc = 0x197A9Cu;
label_197a9c:
    // 0x197a9c: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x197a9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197aa0: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x197AA0u;
    SET_GPR_U32(ctx, 31, 0x197AA8u);
    ctx->pc = 0x197AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197AA0u;
            // 0x197aa4: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197AA8u; }
        if (ctx->pc != 0x197AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197AA8u; }
        if (ctx->pc != 0x197AA8u) { return; }
    }
    ctx->pc = 0x197AA8u;
label_197aa8:
    // 0x197aa8: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x197aa8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_197aac:
    // 0x197aac: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x197aacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x197ab0: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x197ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x197ab4: 0xe42021  addu        $a0, $a3, $a0
    ctx->pc = 0x197ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x197ab8: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x197ab8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x197abc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x197abcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x197ac0: 0x4303c  dsll32      $a2, $a0, 0
    ctx->pc = 0x197ac0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197ac4: 0x3c035000  lui         $v1, 0x5000
    ctx->pc = 0x197ac4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20480 << 16));
    // 0x197ac8: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x197ac8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x197acc: 0xe32025  or          $a0, $a3, $v1
    ctx->pc = 0x197accu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x197ad0: 0xfc460000  sd          $a2, 0x0($v0)
    ctx->pc = 0x197ad0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x197ad4: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x197ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x197ad8: 0xac450008  sw          $a1, 0x8($v0)
    ctx->pc = 0x197ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x197adc: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x197adcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197ae0: 0xac44000c  sw          $a0, 0xC($v0)
    ctx->pc = 0x197ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x197ae4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x197ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x197ae8: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x197ae8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x197aec: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x197aecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197af0: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x197af0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x197af4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x197af4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x197af8: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x197af8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x197afc: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x197afcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x197b00: 0xfc450010  sd          $a1, 0x10($v0)
    ctx->pc = 0x197b00u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 5));
    // 0x197b04: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x197b04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x197b08: 0x12230012  beq         $s1, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x197B08u;
    {
        const bool branch_taken_0x197b08 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x197B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197B08u;
            // 0x197b0c: 0xfc440018  sd          $a0, 0x18($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197b08) {
            ctx->pc = 0x197B54u;
            goto label_197b54;
        }
    }
    ctx->pc = 0x197B10u;
    // 0x197b10: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x197b10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x197b14: 0x1223000a  beq         $s1, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x197B14u;
    {
        const bool branch_taken_0x197b14 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x197B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197B14u;
            // 0x197b18: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197b14) {
            ctx->pc = 0x197B40u;
            goto label_197b40;
        }
    }
    ctx->pc = 0x197B1Cu;
    // 0x197b1c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197B1Cu;
    {
        const bool branch_taken_0x197b1c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x197B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197B1Cu;
            // 0x197b20: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197b1c) {
            ctx->pc = 0x197B2Cu;
            goto label_197b2c;
        }
    }
    ctx->pc = 0x197B24u;
    // 0x197b24: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x197B24u;
    {
        const bool branch_taken_0x197b24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197B24u;
            // 0x197b28: 0x2293c  dsll32      $a1, $v0, 4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197b24) {
            ctx->pc = 0x197B80u;
            goto label_197b80;
        }
    }
    ctx->pc = 0x197B2Cu;
label_197b2c:
    // 0x197b2c: 0x24030047  addiu       $v1, $zero, 0x47
    ctx->pc = 0x197b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x197b30: 0xfc30fdd0  sd          $s0, -0x230($at)
    ctx->pc = 0x197b30u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966736), GPR_U64(ctx, 16));
    // 0x197b34: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x197b34u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197b38: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x197B38u;
    {
        const bool branch_taken_0x197b38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197B38u;
            // 0x197b3c: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197b38) {
            ctx->pc = 0x197B7Cu;
            goto label_197b7c;
        }
    }
    ctx->pc = 0x197B40u;
label_197b40:
    // 0x197b40: 0x24030048  addiu       $v1, $zero, 0x48
    ctx->pc = 0x197b40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x197b44: 0xfc30fdd8  sd          $s0, -0x228($at)
    ctx->pc = 0x197b44u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966744), GPR_U64(ctx, 16));
    // 0x197b48: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x197b48u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197b4c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x197B4Cu;
    {
        const bool branch_taken_0x197b4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197B4Cu;
            // 0x197b50: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197b4c) {
            ctx->pc = 0x197B7Cu;
            goto label_197b7c;
        }
    }
    ctx->pc = 0x197B54u;
label_197b54:
    // 0x197b54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197b54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197b58: 0x24040047  addiu       $a0, $zero, 0x47
    ctx->pc = 0x197b58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x197b5c: 0xfc30fdd0  sd          $s0, -0x230($at)
    ctx->pc = 0x197b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966736), GPR_U64(ctx, 16));
    // 0x197b60: 0x24030048  addiu       $v1, $zero, 0x48
    ctx->pc = 0x197b60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x197b64: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197b64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197b68: 0xfc30fdd8  sd          $s0, -0x228($at)
    ctx->pc = 0x197b68u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966744), GPR_U64(ctx, 16));
    // 0x197b6c: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x197b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197b70: 0xfc440028  sd          $a0, 0x28($v0)
    ctx->pc = 0x197b70u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 4));
    // 0x197b74: 0xfc500030  sd          $s0, 0x30($v0)
    ctx->pc = 0x197b74u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 16));
    // 0x197b78: 0xfc430038  sd          $v1, 0x38($v0)
    ctx->pc = 0x197b78u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_197b7c:
    // 0x197b7c: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x197b7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_197b80:
    // 0x197b80: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x197b80u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x197b84: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x197b84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x197b88: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x197b88u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197b8c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x197b8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197b90: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x197B90u;
    SET_GPR_U32(ctx, 31, 0x197B98u);
    ctx->pc = 0x197B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197B90u;
            // 0x197b94: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197B98u; }
        if (ctx->pc != 0x197B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197B98u; }
        if (ctx->pc != 0x197B98u) { return; }
    }
    ctx->pc = 0x197B98u;
label_197b98:
    // 0x197b98: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x197b98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x197b9c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x197b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x197ba0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x197ba0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x197ba4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x197ba4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x197ba8: 0x3e00008  jr          $ra
    ctx->pc = 0x197BA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197BA8u;
            // 0x197bac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19792Cu: goto label_19792c;
            case 0x197944u: goto label_197944;
            case 0x197948u: goto label_197948;
            case 0x197998u: goto label_197998;
            case 0x1979A0u: goto label_1979a0;
            case 0x1979A8u: goto label_1979a8;
            case 0x1979B0u: goto label_1979b0;
            case 0x1979B8u: goto label_1979b8;
            case 0x1979C0u: goto label_1979c0;
            case 0x1979C8u: goto label_1979c8;
            case 0x1979CCu: goto label_1979cc;
            case 0x197A24u: goto label_197a24;
            case 0x197A2Cu: goto label_197a2c;
            case 0x197A34u: goto label_197a34;
            case 0x197A3Cu: goto label_197a3c;
            case 0x197A44u: goto label_197a44;
            case 0x197A48u: goto label_197a48;
            case 0x197A4Cu: goto label_197a4c;
            case 0x197A94u: goto label_197a94;
            case 0x197A9Cu: goto label_197a9c;
            case 0x197AA8u: goto label_197aa8;
            case 0x197AACu: goto label_197aac;
            case 0x197B2Cu: goto label_197b2c;
            case 0x197B40u: goto label_197b40;
            case 0x197B54u: goto label_197b54;
            case 0x197B7Cu: goto label_197b7c;
            case 0x197B80u: goto label_197b80;
            case 0x197B98u: goto label_197b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197BB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
