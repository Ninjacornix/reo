#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001598C8
// Address: 0x1598c8 - 0x159fb0
void sub_001598C8_0x1598c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001598C8_0x1598c8");
#endif

    switch (ctx->pc) {
        case 0x159924u: goto label_159924;
        case 0x159e48u: goto label_159e48;
        case 0x159ed8u: goto label_159ed8;
        case 0x159f5cu: goto label_159f5c;
        case 0x159f74u: goto label_159f74;
        case 0x159f8cu: goto label_159f8c;
        default: break;
    }

    ctx->pc = 0x1598c8u;

    // 0x1598c8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1598c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1598cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1598ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1598d0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1598d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1598d4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1598d4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1598d8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1598d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1598dc: 0x261101d0  addiu       $s1, $s0, 0x1D0
    ctx->pc = 0x1598dcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 464));
    // 0x1598e0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1598e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1598e4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1598e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1598e8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1598e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1598ec: 0x26130348  addiu       $s3, $s0, 0x348
    ctx->pc = 0x1598ecu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 840));
    // 0x1598f0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1598f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1598f4: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x1598f4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x1598f8: 0xae020384  sw          $v0, 0x384($s0)
    ctx->pc = 0x1598f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 900), GPR_U32(ctx, 2));
    // 0x1598fc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1598fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x159900: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x159900u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x159904: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x159904u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x159908: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x159908u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15990c: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x15990cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159910: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x159910u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x159914: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x159914u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x159918: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x159918u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15991c: 0x40f809  jalr        $v0
    ctx->pc = 0x15991Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x159924u);
        ctx->pc = 0x159920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15991Cu;
            // 0x159920: 0xae230034  sw          $v1, 0x34($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159924u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159924u: goto label_159924;
            case 0x1599B8u: goto label_1599b8;
            case 0x159A30u: goto label_159a30;
            case 0x159A3Cu: goto label_159a3c;
            case 0x159A78u: goto label_159a78;
            case 0x159A88u: goto label_159a88;
            case 0x159AC0u: goto label_159ac0;
            case 0x159ACCu: goto label_159acc;
            case 0x159B08u: goto label_159b08;
            case 0x159B14u: goto label_159b14;
            case 0x159B48u: goto label_159b48;
            case 0x159B54u: goto label_159b54;
            case 0x159B90u: goto label_159b90;
            case 0x159B9Cu: goto label_159b9c;
            case 0x159BD0u: goto label_159bd0;
            case 0x159BD4u: goto label_159bd4;
            case 0x159C10u: goto label_159c10;
            case 0x159C18u: goto label_159c18;
            case 0x159C50u: goto label_159c50;
            case 0x159C5Cu: goto label_159c5c;
            case 0x159C98u: goto label_159c98;
            case 0x159CA8u: goto label_159ca8;
            case 0x159CF8u: goto label_159cf8;
            case 0x159D30u: goto label_159d30;
            case 0x159D3Cu: goto label_159d3c;
            case 0x159D78u: goto label_159d78;
            case 0x159D84u: goto label_159d84;
            case 0x159DD8u: goto label_159dd8;
            case 0x159DE0u: goto label_159de0;
            case 0x159E30u: goto label_159e30;
            case 0x159E38u: goto label_159e38;
            case 0x159E48u: goto label_159e48;
            case 0x159EA0u: goto label_159ea0;
            case 0x159EA4u: goto label_159ea4;
            case 0x159EB0u: goto label_159eb0;
            case 0x159EC8u: goto label_159ec8;
            case 0x159ECCu: goto label_159ecc;
            case 0x159ED8u: goto label_159ed8;
            case 0x159EE8u: goto label_159ee8;
            case 0x159EFCu: goto label_159efc;
            case 0x159F5Cu: goto label_159f5c;
            case 0x159F74u: goto label_159f74;
            case 0x159F8Cu: goto label_159f8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159924u; }
            if (ctx->pc != 0x159924u) { return; }
        }
        }
    }
    ctx->pc = 0x159924u;
label_159924:
    // 0x159924: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x159924u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x159928: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x159928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x15992c: 0x623824  and         $a3, $v1, $v0
    ctx->pc = 0x15992cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x159930: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x159930u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x159934: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x159934u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x159938: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159938u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x15993c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x15993cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159940: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159940u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159944: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159944u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159948: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159948u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15994c: 0x90e40000  lbu         $a0, 0x0($a3)
    ctx->pc = 0x15994cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159950: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159950u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159954: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159954u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159958: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159958u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15995c: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x15995cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159960: 0x328c0  sll         $a1, $v1, 3
    ctx->pc = 0x159960u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x159964: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x159964u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x159968: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159968u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15996c: 0x28a30020  slti        $v1, $a1, 0x20
    ctx->pc = 0x15996cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x159970: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159970u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159974: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x159974u;
    {
        const bool branch_taken_0x159974 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x159978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159974u;
            // 0x159978: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159974) {
            ctx->pc = 0x1599B8u;
            goto label_1599b8;
        }
    }
    ctx->pc = 0x15997Cu;
    // 0x15997c: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x15997cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159980: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159980u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159984: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159984u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159988: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159988u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x15998c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15998cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159990: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159990u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159994: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159994u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159998: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159998u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x15999c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15999cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1599a0: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x1599a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1599a4: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x1599a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1599a8: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x1599a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x1599ac: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x1599acu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1599b0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1599b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1599b4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1599b4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
label_1599b8:
    // 0x1599b8: 0xa61804  sllv        $v1, $a2, $a1
    ctx->pc = 0x1599b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x1599bc: 0x38a20000  xori        $v0, $a1, 0x0
    ctx->pc = 0x1599bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)0);
    // 0x1599c0: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1599c0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1599c4: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x1599c4u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1599c8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1599c8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1599cc: 0x62400b  movn        $t0, $v1, $v0
    ctx->pc = 0x1599ccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 3));
    // 0x1599d0: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x1599d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1599d4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1599d4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1599d8: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x1599d8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1599dc: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x1599dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1599e0: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1599e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x1599e4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1599e4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1599e8: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x1599e8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1599ec: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x1599ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1599f0: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x1599f0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1599f4: 0x28a40014  slti        $a0, $a1, 0x14
    ctx->pc = 0x1599f4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1599f8: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x1599f8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x1599fc: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1599fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159a00: 0x1480001d  bnez        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x159A00u;
    {
        const bool branch_taken_0x159a00 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x159A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159A00u;
            // 0x159a04: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159a00) {
            ctx->pc = 0x159A78u;
            goto label_159a78;
        }
    }
    ctx->pc = 0x159A08u;
    // 0x159a08: 0x24a5ffec  addiu       $a1, $a1, -0x14
    ctx->pc = 0x159a08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967276));
    // 0x159a0c: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x159A0Cu;
    {
        const bool branch_taken_0x159a0c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x159A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159A0Cu;
            // 0x159a10: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159a0c) {
            ctx->pc = 0x159A30u;
            goto label_159a30;
        }
    }
    ctx->pc = 0x159A14u;
    // 0x159a14: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x159a14u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x159a18: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x159a18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x159a1c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x159a1cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x159a20: 0x81d02  srl         $v1, $t0, 20
    ctx->pc = 0x159a20u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x159a24: 0xa64004  sllv        $t0, $a2, $a1
    ctx->pc = 0x159a24u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159a28: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x159A28u;
    {
        const bool branch_taken_0x159a28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159A28u;
            // 0x159a2c: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159a28) {
            ctx->pc = 0x159A3Cu;
            goto label_159a3c;
        }
    }
    ctx->pc = 0x159A30u;
label_159a30:
    // 0x159a30: 0x81502  srl         $v0, $t0, 20
    ctx->pc = 0x159a30u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x159a34: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159a34u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159a38: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x159a38u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_159a3c:
    // 0x159a3c: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159a3cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159a40: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159a40u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159a44: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159a44u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159a48: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159a48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159a4c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159a4cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159a50: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159a50u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159a54: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159a54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159a58: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159a58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159a5c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159a5cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159a60: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159a60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159a64: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159a64u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159a68: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159a68u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159a6c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159a6cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159a70: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x159A70u;
    {
        const bool branch_taken_0x159a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159A70u;
            // 0x159a74: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159a70) {
            ctx->pc = 0x159A88u;
            goto label_159a88;
        }
    }
    ctx->pc = 0x159A78u;
label_159a78:
    // 0x159a78: 0x81502  srl         $v0, $t0, 20
    ctx->pc = 0x159a78u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x159a7c: 0x84300  sll         $t0, $t0, 12
    ctx->pc = 0x159a7cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 12));
    // 0x159a80: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x159a80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x159a84: 0x24a5000c  addiu       $a1, $a1, 0xC
    ctx->pc = 0x159a84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
label_159a88:
    // 0x159a88: 0x28a20014  slti        $v0, $a1, 0x14
    ctx->pc = 0x159a88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x159a8c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x159A8Cu;
    {
        const bool branch_taken_0x159a8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x159A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159A8Cu;
            // 0x159a90: 0x81502  srl         $v0, $t0, 20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159a8c) {
            ctx->pc = 0x159B08u;
            goto label_159b08;
        }
    }
    ctx->pc = 0x159A94u;
    // 0x159a94: 0x24a5ffec  addiu       $a1, $a1, -0x14
    ctx->pc = 0x159a94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967276));
    // 0x159a98: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x159A98u;
    {
        const bool branch_taken_0x159a98 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x159A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159A98u;
            // 0x159a9c: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159a98) {
            ctx->pc = 0x159AC0u;
            goto label_159ac0;
        }
    }
    ctx->pc = 0x159AA0u;
    // 0x159aa0: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x159aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x159aa4: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x159aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x159aa8: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x159aa8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x159aac: 0x81d02  srl         $v1, $t0, 20
    ctx->pc = 0x159aacu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x159ab0: 0xa64004  sllv        $t0, $a2, $a1
    ctx->pc = 0x159ab0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159ab4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x159AB4u;
    {
        const bool branch_taken_0x159ab4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159AB4u;
            // 0x159ab8: 0xae230004  sw          $v1, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159ab4) {
            ctx->pc = 0x159ACCu;
            goto label_159acc;
        }
    }
    ctx->pc = 0x159ABCu;
    // 0x159abc: 0x0  nop
    ctx->pc = 0x159abcu;
    // NOP
label_159ac0:
    // 0x159ac0: 0x81502  srl         $v0, $t0, 20
    ctx->pc = 0x159ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x159ac4: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159ac4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159ac8: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x159ac8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
label_159acc:
    // 0x159acc: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159accu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159ad0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159ad0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159ad4: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159ad4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159ad8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159ad8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159adc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159adcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159ae0: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159ae0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159ae4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159ae4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159ae8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159ae8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159aec: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159aecu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159af0: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159af0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159af4: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159af4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159af8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159af8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159afc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159afcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159b00: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x159B00u;
    {
        const bool branch_taken_0x159b00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159B00u;
            // 0x159b04: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159b00) {
            ctx->pc = 0x159B14u;
            goto label_159b14;
        }
    }
    ctx->pc = 0x159B08u;
label_159b08:
    // 0x159b08: 0x84300  sll         $t0, $t0, 12
    ctx->pc = 0x159b08u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 12));
    // 0x159b0c: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x159b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x159b10: 0x24a5000c  addiu       $a1, $a1, 0xC
    ctx->pc = 0x159b10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
label_159b14:
    // 0x159b14: 0x28a2001c  slti        $v0, $a1, 0x1C
    ctx->pc = 0x159b14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x159b18: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x159B18u;
    {
        const bool branch_taken_0x159b18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x159B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159B18u;
            // 0x159b1c: 0x81702  srl         $v0, $t0, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159b18) {
            ctx->pc = 0x159B90u;
            goto label_159b90;
        }
    }
    ctx->pc = 0x159B20u;
    // 0x159b20: 0x24a5ffe4  addiu       $a1, $a1, -0x1C
    ctx->pc = 0x159b20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967268));
    // 0x159b24: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x159B24u;
    {
        const bool branch_taken_0x159b24 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x159B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159B24u;
            // 0x159b28: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159b24) {
            ctx->pc = 0x159B48u;
            goto label_159b48;
        }
    }
    ctx->pc = 0x159B2Cu;
    // 0x159b2c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x159b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x159b30: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x159b30u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x159b34: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x159b34u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x159b38: 0x81f02  srl         $v1, $t0, 28
    ctx->pc = 0x159b38u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x159b3c: 0xa64004  sllv        $t0, $a2, $a1
    ctx->pc = 0x159b3cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159b40: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x159B40u;
    {
        const bool branch_taken_0x159b40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159B40u;
            // 0x159b44: 0xae030278  sw          $v1, 0x278($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 632), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159b40) {
            ctx->pc = 0x159B54u;
            goto label_159b54;
        }
    }
    ctx->pc = 0x159B48u;
label_159b48:
    // 0x159b48: 0x81702  srl         $v0, $t0, 28
    ctx->pc = 0x159b48u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x159b4c: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159b4cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159b50: 0xae020278  sw          $v0, 0x278($s0)
    ctx->pc = 0x159b50u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 632), GPR_U32(ctx, 2));
label_159b54:
    // 0x159b54: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159b54u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159b58: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159b58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159b5c: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159b5cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159b60: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159b60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159b64: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159b64u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159b68: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159b68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159b6c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159b6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159b70: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159b70u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159b74: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159b74u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159b78: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159b78u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159b7c: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159b7cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159b80: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159b80u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159b84: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159b84u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159b88: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x159B88u;
    {
        const bool branch_taken_0x159b88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159B88u;
            // 0x159b8c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159b88) {
            ctx->pc = 0x159B9Cu;
            goto label_159b9c;
        }
    }
    ctx->pc = 0x159B90u;
label_159b90:
    // 0x159b90: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x159b90u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x159b94: 0xae020278  sw          $v0, 0x278($s0)
    ctx->pc = 0x159b94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 632), GPR_U32(ctx, 2));
    // 0x159b98: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x159b98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
label_159b9c:
    // 0x159b9c: 0x28a2001c  slti        $v0, $a1, 0x1C
    ctx->pc = 0x159b9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x159ba0: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x159BA0u;
    {
        const bool branch_taken_0x159ba0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x159BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159BA0u;
            // 0x159ba4: 0x82702  srl         $a0, $t0, 28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159ba0) {
            ctx->pc = 0x159C10u;
            goto label_159c10;
        }
    }
    ctx->pc = 0x159BA8u;
    // 0x159ba8: 0x24a5ffe4  addiu       $a1, $a1, -0x1C
    ctx->pc = 0x159ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967268));
    // 0x159bac: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x159BACu;
    {
        const bool branch_taken_0x159bac = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x159BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159BACu;
            // 0x159bb0: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159bac) {
            ctx->pc = 0x159BD0u;
            goto label_159bd0;
        }
    }
    ctx->pc = 0x159BB4u;
    // 0x159bb4: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x159bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x159bb8: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x159bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x159bbc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x159bbcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x159bc0: 0x82702  srl         $a0, $t0, 28
    ctx->pc = 0x159bc0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x159bc4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x159BC4u;
    {
        const bool branch_taken_0x159bc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159BC4u;
            // 0x159bc8: 0xa64004  sllv        $t0, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159bc4) {
            ctx->pc = 0x159BD4u;
            goto label_159bd4;
        }
    }
    ctx->pc = 0x159BCCu;
    // 0x159bcc: 0x0  nop
    ctx->pc = 0x159bccu;
    // NOP
label_159bd0:
    // 0x159bd0: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159bd0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_159bd4:
    // 0x159bd4: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159bd4u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159bd8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159bd8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159bdc: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159bdcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159be0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159be0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159be4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159be4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159be8: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159be8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159bec: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159becu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159bf0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159bf0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159bf4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159bf4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159bf8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159bf8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159bfc: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159bfcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159c00: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159c00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159c04: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159c04u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159c08: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x159C08u;
    {
        const bool branch_taken_0x159c08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159C08u;
            // 0x159c0c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159c08) {
            ctx->pc = 0x159C18u;
            goto label_159c18;
        }
    }
    ctx->pc = 0x159C10u;
label_159c10:
    // 0x159c10: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x159c10u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x159c14: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x159c14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
label_159c18:
    // 0x159c18: 0x28a2000e  slti        $v0, $a1, 0xE
    ctx->pc = 0x159c18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)14) ? 1 : 0);
    // 0x159c1c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x159C1Cu;
    {
        const bool branch_taken_0x159c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x159C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159C1Cu;
            // 0x159c20: 0xae240010  sw          $a0, 0x10($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159c1c) {
            ctx->pc = 0x159C98u;
            goto label_159c98;
        }
    }
    ctx->pc = 0x159C24u;
    // 0x159c24: 0x24a5fff2  addiu       $a1, $a1, -0xE
    ctx->pc = 0x159c24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967282));
    // 0x159c28: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x159C28u;
    {
        const bool branch_taken_0x159c28 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x159C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159C28u;
            // 0x159c2c: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159c28) {
            ctx->pc = 0x159C50u;
            goto label_159c50;
        }
    }
    ctx->pc = 0x159C30u;
    // 0x159c30: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x159c30u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x159c34: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x159c34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x159c38: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x159c38u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x159c3c: 0x81b82  srl         $v1, $t0, 14
    ctx->pc = 0x159c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 14));
    // 0x159c40: 0xa64004  sllv        $t0, $a2, $a1
    ctx->pc = 0x159c40u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159c44: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x159C44u;
    {
        const bool branch_taken_0x159c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159C44u;
            // 0x159c48: 0xae03027c  sw          $v1, 0x27C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 636), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159c44) {
            ctx->pc = 0x159C5Cu;
            goto label_159c5c;
        }
    }
    ctx->pc = 0x159C4Cu;
    // 0x159c4c: 0x0  nop
    ctx->pc = 0x159c4cu;
    // NOP
label_159c50:
    // 0x159c50: 0x81382  srl         $v0, $t0, 14
    ctx->pc = 0x159c50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 14));
    // 0x159c54: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159c54u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159c58: 0xae02027c  sw          $v0, 0x27C($s0)
    ctx->pc = 0x159c58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 636), GPR_U32(ctx, 2));
label_159c5c:
    // 0x159c5c: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159c5cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159c60: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159c60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159c64: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159c64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159c68: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159c68u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159c6c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159c6cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159c70: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159c70u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159c74: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159c74u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159c78: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159c78u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159c7c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159c7cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159c80: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159c80u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159c84: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159c84u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159c88: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159c88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159c8c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159c8cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159c90: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x159C90u;
    {
        const bool branch_taken_0x159c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159C90u;
            // 0x159c94: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159c90) {
            ctx->pc = 0x159CA8u;
            goto label_159ca8;
        }
    }
    ctx->pc = 0x159C98u;
label_159c98:
    // 0x159c98: 0x81382  srl         $v0, $t0, 14
    ctx->pc = 0x159c98u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 14));
    // 0x159c9c: 0x84480  sll         $t0, $t0, 18
    ctx->pc = 0x159c9cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 18));
    // 0x159ca0: 0xae02027c  sw          $v0, 0x27C($s0)
    ctx->pc = 0x159ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 636), GPR_U32(ctx, 2));
    // 0x159ca4: 0x24a50012  addiu       $a1, $a1, 0x12
    ctx->pc = 0x159ca4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 18));
label_159ca8:
    // 0x159ca8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x159ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x159cac: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x159cacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x159cb0: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x159CB0u;
    {
        const bool branch_taken_0x159cb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x159cb0) {
            ctx->pc = 0x159CB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x159CB0u;
            // 0x159cb4: 0x84040  sll         $t0, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x159CF8u;
            goto label_159cf8;
        }
    }
    ctx->pc = 0x159CB8u;
    // 0x159cb8: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x159cb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x159cbc: 0xa64004  sllv        $t0, $a2, $a1
    ctx->pc = 0x159cbcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159cc0: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159cc0u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159cc4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159cc4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159cc8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159cc8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159ccc: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159cccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159cd0: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159cd0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159cd4: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159cd4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159cd8: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159cd8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159cdc: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159cdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159ce0: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159ce0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159ce4: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159ce4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159ce8: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159ce8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159cec: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159cecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159cf0: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159cf0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159cf4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159cf4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
label_159cf8:
    // 0x159cf8: 0x28a20016  slti        $v0, $a1, 0x16
    ctx->pc = 0x159cf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x159cfc: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x159CFCu;
    {
        const bool branch_taken_0x159cfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x159D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159CFCu;
            // 0x159d00: 0x81582  srl         $v0, $t0, 22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159cfc) {
            ctx->pc = 0x159D78u;
            goto label_159d78;
        }
    }
    ctx->pc = 0x159D04u;
    // 0x159d04: 0x24a5ffea  addiu       $a1, $a1, -0x16
    ctx->pc = 0x159d04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967274));
    // 0x159d08: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x159D08u;
    {
        const bool branch_taken_0x159d08 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x159D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159D08u;
            // 0x159d0c: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159d08) {
            ctx->pc = 0x159D30u;
            goto label_159d30;
        }
    }
    ctx->pc = 0x159D10u;
    // 0x159d10: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x159d10u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x159d14: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x159d14u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x159d18: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x159d18u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x159d1c: 0x81d82  srl         $v1, $t0, 22
    ctx->pc = 0x159d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 22));
    // 0x159d20: 0xa64004  sllv        $t0, $a2, $a1
    ctx->pc = 0x159d20u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159d24: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x159D24u;
    {
        const bool branch_taken_0x159d24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159D24u;
            // 0x159d28: 0xae030280  sw          $v1, 0x280($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 640), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159d24) {
            ctx->pc = 0x159D3Cu;
            goto label_159d3c;
        }
    }
    ctx->pc = 0x159D2Cu;
    // 0x159d2c: 0x0  nop
    ctx->pc = 0x159d2cu;
    // NOP
label_159d30:
    // 0x159d30: 0x81582  srl         $v0, $t0, 22
    ctx->pc = 0x159d30u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 22));
    // 0x159d34: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159d34u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159d38: 0xae020280  sw          $v0, 0x280($s0)
    ctx->pc = 0x159d38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 640), GPR_U32(ctx, 2));
label_159d3c:
    // 0x159d3c: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159d3cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159d40: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159d40u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159d44: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159d44u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159d48: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159d48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159d4c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159d4cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159d50: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159d50u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159d54: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159d54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159d58: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159d58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159d5c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159d5cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159d60: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159d60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159d64: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159d64u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159d68: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159d68u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159d6c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159d6cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159d70: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x159D70u;
    {
        const bool branch_taken_0x159d70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159D70u;
            // 0x159d74: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159d70) {
            ctx->pc = 0x159D84u;
            goto label_159d84;
        }
    }
    ctx->pc = 0x159D78u;
label_159d78:
    // 0x159d78: 0x84280  sll         $t0, $t0, 10
    ctx->pc = 0x159d78u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 10));
    // 0x159d7c: 0xae020280  sw          $v0, 0x280($s0)
    ctx->pc = 0x159d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 640), GPR_U32(ctx, 2));
    // 0x159d80: 0x24a5000a  addiu       $a1, $a1, 0xA
    ctx->pc = 0x159d80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10));
label_159d84:
    // 0x159d84: 0x817c2  srl         $v0, $t0, 31
    ctx->pc = 0x159d84u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x159d88: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x159d88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x159d8c: 0x14a30012  bne         $a1, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x159D8Cu;
    {
        const bool branch_taken_0x159d8c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x159D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159D8Cu;
            // 0x159d90: 0xae020284  sw          $v0, 0x284($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 644), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159d8c) {
            ctx->pc = 0x159DD8u;
            goto label_159dd8;
        }
    }
    ctx->pc = 0x159D94u;
    // 0x159d94: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159d94u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159d98: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159d98u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159d9c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159d9cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159da0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x159da0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159da4: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159da4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159da8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159da8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159dac: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159dacu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159db0: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159db0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159db4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159db4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159db8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159db8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159dbc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159dbcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159dc0: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159dc0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159dc4: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159dc4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159dc8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159dc8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159dcc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159dccu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159dd0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x159DD0u;
    {
        const bool branch_taken_0x159dd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159DD0u;
            // 0x159dd4: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159dd0) {
            ctx->pc = 0x159DE0u;
            goto label_159de0;
        }
    }
    ctx->pc = 0x159DD8u;
label_159dd8:
    // 0x159dd8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x159dd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x159ddc: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x159ddcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
label_159de0:
    // 0x159de0: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x159de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x159de4: 0x14a20012  bne         $a1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x159DE4u;
    {
        const bool branch_taken_0x159de4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x159DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159DE4u;
            // 0x159de8: 0x827c2  srl         $a0, $t0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159de4) {
            ctx->pc = 0x159E30u;
            goto label_159e30;
        }
    }
    ctx->pc = 0x159DECu;
    // 0x159dec: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159decu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159df0: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159df0u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159df4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159df4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159df8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x159df8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159dfc: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159dfcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e00: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e04: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159e04u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159e08: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159e08u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e0c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159e0cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159e10: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e14: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159e14u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159e18: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159e18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e1c: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159e1cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159e20: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e20u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e24: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159e24u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159e28: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x159E28u;
    {
        const bool branch_taken_0x159e28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159E28u;
            // 0x159e2c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159e28) {
            ctx->pc = 0x159E38u;
            goto label_159e38;
        }
    }
    ctx->pc = 0x159E30u;
label_159e30:
    // 0x159e30: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x159e30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x159e34: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x159e34u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
label_159e38:
    // 0x159e38: 0x1080001d  beqz        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x159E38u;
    {
        const bool branch_taken_0x159e38 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x159E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159E38u;
            // 0x159e3c: 0x2404003f  addiu       $a0, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159e38) {
            ctx->pc = 0x159EB0u;
            goto label_159eb0;
        }
    }
    ctx->pc = 0x159E40u;
    // 0x159e40: 0x28a20018  slti        $v0, $a1, 0x18
    ctx->pc = 0x159e40u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x159e44: 0x0  nop
    ctx->pc = 0x159e44u;
    // NOP
label_159e48:
    // 0x159e48: 0x54400015  bnel        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x159E48u;
    {
        const bool branch_taken_0x159e48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x159e48) {
            ctx->pc = 0x159E4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x159E48u;
            // 0x159e4c: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x159EA0u;
            goto label_159ea0;
        }
    }
    ctx->pc = 0x159E50u;
    // 0x159e50: 0x24a5ffe8  addiu       $a1, $a1, -0x18
    ctx->pc = 0x159e50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967272));
    // 0x159e54: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x159e54u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159e58: 0xa61804  sllv        $v1, $a2, $a1
    ctx->pc = 0x159e58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x159e5c: 0x80e60000  lb          $a2, 0x0($a3)
    ctx->pc = 0x159e5cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e60: 0x38a20000  xori        $v0, $a1, 0x0
    ctx->pc = 0x159e60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)0);
    // 0x159e64: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e64u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e68: 0x62400b  movn        $t0, $v1, $v0
    ctx->pc = 0x159e68u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 3));
    // 0x159e6c: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159e6cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e70: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159e70u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159e74: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e74u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e78: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x159e78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e7c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e7cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e80: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x159e80u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x159e84: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x159e84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x159e88: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159e88u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159e8c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x159e8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x159e90: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x159e90u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x159e94: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x159e94u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x159e98: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x159E98u;
    {
        const bool branch_taken_0x159e98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159E98u;
            // 0x159e9c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159e98) {
            ctx->pc = 0x159EA4u;
            goto label_159ea4;
        }
    }
    ctx->pc = 0x159EA0u;
label_159ea0:
    // 0x159ea0: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x159ea0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
label_159ea4:
    // 0x159ea4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x159ea4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x159ea8: 0x481ffe7  bgez        $a0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x159EA8u;
    {
        const bool branch_taken_0x159ea8 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x159EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159EA8u;
            // 0x159eac: 0x28a20018  slti        $v0, $a1, 0x18 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)24) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x159ea8) {
            ctx->pc = 0x159E48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_159e48;
        }
    }
    ctx->pc = 0x159EB0u;
label_159eb0:
    // 0x159eb0: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x159eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x159eb4: 0x14a20004  bne         $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x159EB4u;
    {
        const bool branch_taken_0x159eb4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x159EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159EB4u;
            // 0x159eb8: 0x827c2  srl         $a0, $t0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159eb4) {
            ctx->pc = 0x159EC8u;
            goto label_159ec8;
        }
    }
    ctx->pc = 0x159EBCu;
    // 0x159ebc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x159ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159ec0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x159EC0u;
    {
        const bool branch_taken_0x159ec0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159EC0u;
            // 0x159ec4: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159ec0) {
            ctx->pc = 0x159ECCu;
            goto label_159ecc;
        }
    }
    ctx->pc = 0x159EC8u;
label_159ec8:
    // 0x159ec8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x159ec8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_159ecc:
    // 0x159ecc: 0x1080000b  beqz        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x159ECCu;
    {
        const bool branch_taken_0x159ecc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x159ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159ECCu;
            // 0x159ed0: 0x2404003f  addiu       $a0, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159ecc) {
            ctx->pc = 0x159EFCu;
            goto label_159efc;
        }
    }
    ctx->pc = 0x159ED4u;
    // 0x159ed4: 0x28a20018  slti        $v0, $a1, 0x18
    ctx->pc = 0x159ed4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)24) ? 1 : 0);
label_159ed8:
    // 0x159ed8: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x159ED8u;
    {
        const bool branch_taken_0x159ed8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x159ed8) {
            ctx->pc = 0x159EDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x159ED8u;
            // 0x159edc: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x159EE8u;
            goto label_159ee8;
        }
    }
    ctx->pc = 0x159EE0u;
    // 0x159ee0: 0x24a5ffe8  addiu       $a1, $a1, -0x18
    ctx->pc = 0x159ee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967272));
    // 0x159ee4: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x159ee4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
label_159ee8:
    // 0x159ee8: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x159ee8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x159eec: 0x0  nop
    ctx->pc = 0x159eecu;
    // NOP
    // 0x159ef0: 0x0  nop
    ctx->pc = 0x159ef0u;
    // NOP
    // 0x159ef4: 0x481fff8  bgez        $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x159EF4u;
    {
        const bool branch_taken_0x159ef4 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x159EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159EF4u;
            // 0x159ef8: 0x28a20018  slti        $v0, $a1, 0x18 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)24) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x159ef4) {
            ctx->pc = 0x159ED8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_159ed8;
        }
    }
    ctx->pc = 0x159EFCu;
label_159efc:
    // 0x159efc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x159efcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x159f00: 0x30a80007  andi        $t0, $a1, 0x7
    ctx->pc = 0x159f00u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)7);
    // 0x159f04: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x159f04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x159f08: 0xa82823  subu        $a1, $a1, $t0
    ctx->pc = 0x159f08u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x159f0c: 0x2463000f  addiu       $v1, $v1, 0xF
    ctx->pc = 0x159f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x159f10: 0x24a50007  addiu       $a1, $a1, 0x7
    ctx->pc = 0x159f10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x159f14: 0x2442000f  addiu       $v0, $v0, 0xF
    ctx->pc = 0x159f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x159f18: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x159f18u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x159f1c: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x159f1cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x159f20: 0x528c3  sra         $a1, $a1, 3
    ctx->pc = 0x159f20u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 3));
    // 0x159f24: 0x432018  mult        $a0, $v0, $v1
    ctx->pc = 0x159f24u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x159f28: 0x8e060348  lw          $a2, 0x348($s0)
    ctx->pc = 0x159f28u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 840)));
    // 0x159f2c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x159f2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x159f30: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x159f30u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159f34: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x159f34u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x159f38: 0x24a5fff8  addiu       $a1, $a1, -0x8
    ctx->pc = 0x159f38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967288));
    // 0x159f3c: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x159f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x159f40: 0xa62823  subu        $a1, $a1, $a2
    ctx->pc = 0x159f40u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x159f44: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x159f44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x159f48: 0xae080350  sw          $t0, 0x350($s0)
    ctx->pc = 0x159f48u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 848), GPR_U32(ctx, 8));
    // 0x159f4c: 0xae040310  sw          $a0, 0x310($s0)
    ctx->pc = 0x159f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 784), GPR_U32(ctx, 4));
    // 0x159f50: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x159f50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159f54: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x159F54u;
    SET_GPR_U32(ctx, 31, 0x159F5Cu);
    ctx->pc = 0x159F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159F54u;
            // 0x159f58: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159F5Cu; }
        if (ctx->pc != 0x159F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159F5Cu; }
        if (ctx->pc != 0x159F5Cu) { return; }
    }
    ctx->pc = 0x159F5Cu;
label_159f5c:
    // 0x159f5c: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x159f5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x159f60: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x159f60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159f64: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x159f64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159f68: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x159f68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x159f6c: 0x40f809  jalr        $v0
    ctx->pc = 0x159F6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x159F74u);
        ctx->pc = 0x159F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159F6Cu;
            // 0x159f70: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159F74u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159924u: goto label_159924;
            case 0x1599B8u: goto label_1599b8;
            case 0x159A30u: goto label_159a30;
            case 0x159A3Cu: goto label_159a3c;
            case 0x159A78u: goto label_159a78;
            case 0x159A88u: goto label_159a88;
            case 0x159AC0u: goto label_159ac0;
            case 0x159ACCu: goto label_159acc;
            case 0x159B08u: goto label_159b08;
            case 0x159B14u: goto label_159b14;
            case 0x159B48u: goto label_159b48;
            case 0x159B54u: goto label_159b54;
            case 0x159B90u: goto label_159b90;
            case 0x159B9Cu: goto label_159b9c;
            case 0x159BD0u: goto label_159bd0;
            case 0x159BD4u: goto label_159bd4;
            case 0x159C10u: goto label_159c10;
            case 0x159C18u: goto label_159c18;
            case 0x159C50u: goto label_159c50;
            case 0x159C5Cu: goto label_159c5c;
            case 0x159C98u: goto label_159c98;
            case 0x159CA8u: goto label_159ca8;
            case 0x159CF8u: goto label_159cf8;
            case 0x159D30u: goto label_159d30;
            case 0x159D3Cu: goto label_159d3c;
            case 0x159D78u: goto label_159d78;
            case 0x159D84u: goto label_159d84;
            case 0x159DD8u: goto label_159dd8;
            case 0x159DE0u: goto label_159de0;
            case 0x159E30u: goto label_159e30;
            case 0x159E38u: goto label_159e38;
            case 0x159E48u: goto label_159e48;
            case 0x159EA0u: goto label_159ea0;
            case 0x159EA4u: goto label_159ea4;
            case 0x159EB0u: goto label_159eb0;
            case 0x159EC8u: goto label_159ec8;
            case 0x159ECCu: goto label_159ecc;
            case 0x159ED8u: goto label_159ed8;
            case 0x159EE8u: goto label_159ee8;
            case 0x159EFCu: goto label_159efc;
            case 0x159F5Cu: goto label_159f5c;
            case 0x159F74u: goto label_159f74;
            case 0x159F8Cu: goto label_159f8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159F74u; }
            if (ctx->pc != 0x159F74u) { return; }
        }
        }
    }
    ctx->pc = 0x159F74u;
label_159f74:
    // 0x159f74: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x159f74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x159f78: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x159f78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159f7c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x159f7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x159f80: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x159f80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x159f84: 0x40f809  jalr        $v0
    ctx->pc = 0x159F84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x159F8Cu);
        ctx->pc = 0x159F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159F84u;
            // 0x159f88: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159F8Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159924u: goto label_159924;
            case 0x1599B8u: goto label_1599b8;
            case 0x159A30u: goto label_159a30;
            case 0x159A3Cu: goto label_159a3c;
            case 0x159A78u: goto label_159a78;
            case 0x159A88u: goto label_159a88;
            case 0x159AC0u: goto label_159ac0;
            case 0x159ACCu: goto label_159acc;
            case 0x159B08u: goto label_159b08;
            case 0x159B14u: goto label_159b14;
            case 0x159B48u: goto label_159b48;
            case 0x159B54u: goto label_159b54;
            case 0x159B90u: goto label_159b90;
            case 0x159B9Cu: goto label_159b9c;
            case 0x159BD0u: goto label_159bd0;
            case 0x159BD4u: goto label_159bd4;
            case 0x159C10u: goto label_159c10;
            case 0x159C18u: goto label_159c18;
            case 0x159C50u: goto label_159c50;
            case 0x159C5Cu: goto label_159c5c;
            case 0x159C98u: goto label_159c98;
            case 0x159CA8u: goto label_159ca8;
            case 0x159CF8u: goto label_159cf8;
            case 0x159D30u: goto label_159d30;
            case 0x159D3Cu: goto label_159d3c;
            case 0x159D78u: goto label_159d78;
            case 0x159D84u: goto label_159d84;
            case 0x159DD8u: goto label_159dd8;
            case 0x159DE0u: goto label_159de0;
            case 0x159E30u: goto label_159e30;
            case 0x159E38u: goto label_159e38;
            case 0x159E48u: goto label_159e48;
            case 0x159EA0u: goto label_159ea0;
            case 0x159EA4u: goto label_159ea4;
            case 0x159EB0u: goto label_159eb0;
            case 0x159EC8u: goto label_159ec8;
            case 0x159ECCu: goto label_159ecc;
            case 0x159ED8u: goto label_159ed8;
            case 0x159EE8u: goto label_159ee8;
            case 0x159EFCu: goto label_159efc;
            case 0x159F5Cu: goto label_159f5c;
            case 0x159F74u: goto label_159f74;
            case 0x159F8Cu: goto label_159f8c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159F8Cu; }
            if (ctx->pc != 0x159F8Cu) { return; }
        }
        }
    }
    ctx->pc = 0x159F8Cu;
label_159f8c:
    // 0x159f8c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x159f8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159f90: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x159f90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x159f94: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x159f94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159f98: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x159f98u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x159f9c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x159f9cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x159fa0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x159fa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x159fa4: 0x3e00008  jr          $ra
    ctx->pc = 0x159FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x159FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159FA4u;
            // 0x159fa8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159924u: goto label_159924;
            case 0x1599B8u: goto label_1599b8;
            case 0x159A30u: goto label_159a30;
            case 0x159A3Cu: goto label_159a3c;
            case 0x159A78u: goto label_159a78;
            case 0x159A88u: goto label_159a88;
            case 0x159AC0u: goto label_159ac0;
            case 0x159ACCu: goto label_159acc;
            case 0x159B08u: goto label_159b08;
            case 0x159B14u: goto label_159b14;
            case 0x159B48u: goto label_159b48;
            case 0x159B54u: goto label_159b54;
            case 0x159B90u: goto label_159b90;
            case 0x159B9Cu: goto label_159b9c;
            case 0x159BD0u: goto label_159bd0;
            case 0x159BD4u: goto label_159bd4;
            case 0x159C10u: goto label_159c10;
            case 0x159C18u: goto label_159c18;
            case 0x159C50u: goto label_159c50;
            case 0x159C5Cu: goto label_159c5c;
            case 0x159C98u: goto label_159c98;
            case 0x159CA8u: goto label_159ca8;
            case 0x159CF8u: goto label_159cf8;
            case 0x159D30u: goto label_159d30;
            case 0x159D3Cu: goto label_159d3c;
            case 0x159D78u: goto label_159d78;
            case 0x159D84u: goto label_159d84;
            case 0x159DD8u: goto label_159dd8;
            case 0x159DE0u: goto label_159de0;
            case 0x159E30u: goto label_159e30;
            case 0x159E38u: goto label_159e38;
            case 0x159E48u: goto label_159e48;
            case 0x159EA0u: goto label_159ea0;
            case 0x159EA4u: goto label_159ea4;
            case 0x159EB0u: goto label_159eb0;
            case 0x159EC8u: goto label_159ec8;
            case 0x159ECCu: goto label_159ecc;
            case 0x159ED8u: goto label_159ed8;
            case 0x159EE8u: goto label_159ee8;
            case 0x159EFCu: goto label_159efc;
            case 0x159F5Cu: goto label_159f5c;
            case 0x159F74u: goto label_159f74;
            case 0x159F8Cu: goto label_159f8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159FACu;
    // 0x159fac: 0x0  nop
    ctx->pc = 0x159facu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
