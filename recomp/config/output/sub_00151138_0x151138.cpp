#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00151138
// Address: 0x151138 - 0x151878
void sub_00151138_0x151138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00151138_0x151138");
#endif

    switch (ctx->pc) {
        case 0x151174u: goto label_151174;
        case 0x151738u: goto label_151738;
        case 0x1517e8u: goto label_1517e8;
        case 0x151814u: goto label_151814;
        case 0x15181cu: goto label_15181c;
        case 0x151824u: goto label_151824;
        default: break;
    }

    ctx->pc = 0x151138u;

    // 0x151138: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x151138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15113c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15113cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x151140: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x151140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x151144: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x151144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x151148: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x151148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15114c: 0x24920128  addiu       $s2, $a0, 0x128
    ctx->pc = 0x15114cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x151150: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x151150u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x151154: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x151154u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151158: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x151158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15115c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15115cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151160: 0xae4304dc  sw          $v1, 0x4DC($s2)
    ctx->pc = 0x151160u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 1244), GPR_U32(ctx, 3));
    // 0x151164: 0x8e4204e4  lw          $v0, 0x4E4($s2)
    ctx->pc = 0x151164u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 1252)));
    // 0x151168: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x151168u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15116c: 0xc054380  jal         func_150E00
    ctx->pc = 0x15116Cu;
    SET_GPR_U32(ctx, 31, 0x151174u);
    ctx->pc = 0x151170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15116Cu;
            // 0x151170: 0xae4204e4  sw          $v0, 0x4E4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 1252), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150E00u;
    if (runtime->hasFunction(0x150E00u)) {
        auto targetFn = runtime->lookupFunction(0x150E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151174u; }
        if (ctx->pc != 0x151174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150E00_0x150e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151174u; }
        if (ctx->pc != 0x151174u) { return; }
    }
    ctx->pc = 0x151174u;
label_151174:
    // 0x151174: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x151174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x151178: 0x2628024  and         $s0, $s3, $v0
    ctx->pc = 0x151178u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x15117c: 0x2701823  subu        $v1, $s3, $s0
    ctx->pc = 0x15117cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x151180: 0x82080000  lb          $t0, 0x0($s0)
    ctx->pc = 0x151180u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151184: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151184u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151188: 0x388c0  sll         $s1, $v1, 3
    ctx->pc = 0x151188u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x15118c: 0x92040000  lbu         $a0, 0x0($s0)
    ctx->pc = 0x15118cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151190: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151190u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151194: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x151194u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151198: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151198u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15119c: 0x92060000  lbu         $a2, 0x0($s0)
    ctx->pc = 0x15119cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1511a0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1511a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1511a4: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x1511a4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1511a8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1511a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1511ac: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1511acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1511b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1511b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1511b4: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1511b4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1511b8: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1511b8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1511bc: 0x1044025  or          $t0, $t0, $a0
    ctx->pc = 0x1511bcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 4));
    // 0x1511c0: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1511c0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1511c4: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1511c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1511c8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1511c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1511cc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1511ccu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1511d0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1511d0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1511d4: 0x1054025  or          $t0, $t0, $a1
    ctx->pc = 0x1511d4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 5));
    // 0x1511d8: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1511d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1511dc: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1511dcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1511e0: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1511e0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1511e4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1511e4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1511e8: 0x1064025  or          $t0, $t0, $a2
    ctx->pc = 0x1511e8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 6));
    // 0x1511ec: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1511ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1511f0: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1511f0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1511f4: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1511F4u;
    {
        const bool branch_taken_0x1511f4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1511F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1511F4u;
            // 0x1511f8: 0x2284004  sllv        $t0, $t0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 17) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1511f4) {
            ctx->pc = 0x151218u;
            goto label_151218;
        }
    }
    ctx->pc = 0x1511FCu;
    // 0x1511fc: 0x111023  negu        $v0, $s1
    ctx->pc = 0x1511fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 17)));
    // 0x151200: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151200u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151204: 0x1021025  or          $v0, $t0, $v0
    ctx->pc = 0x151204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151208: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x151208u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x15120c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15120Cu;
    {
        const bool branch_taken_0x15120c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15120Cu;
            // 0x151210: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15120c) {
            ctx->pc = 0x151220u;
            goto label_151220;
        }
    }
    ctx->pc = 0x151214u;
    // 0x151214: 0x0  nop
    ctx->pc = 0x151214u;
    // NOP
label_151218:
    // 0x151218: 0xae480000  sw          $t0, 0x0($s2)
    ctx->pc = 0x151218u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 8));
    // 0x15121c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x15121cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_151220:
    // 0x151220: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151220u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151224: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151224u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151228: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151228u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15122c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x15122cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151230: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151230u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151234: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151234u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151238: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151238u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15123c: 0x2a220014  slti        $v0, $s1, 0x14
    ctx->pc = 0x15123cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x151240: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151240u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151244: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151244u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151248: 0x92040000  lbu         $a0, 0x0($s0)
    ctx->pc = 0x151248u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15124c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x15124cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151250: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x151250u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151254: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151254u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151258: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151258u;
    {
        const bool branch_taken_0x151258 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15125Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151258u;
            // 0x15125c: 0xe43825  or          $a3, $a3, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151258) {
            ctx->pc = 0x1512D0u;
            goto label_1512d0;
        }
    }
    ctx->pc = 0x151260u;
    // 0x151260: 0x2631ffec  addiu       $s1, $s1, -0x14
    ctx->pc = 0x151260u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967276));
    // 0x151264: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x151264u;
    {
        const bool branch_taken_0x151264 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151264u;
            // 0x151268: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151264) {
            ctx->pc = 0x151288u;
            goto label_151288;
        }
    }
    ctx->pc = 0x15126Cu;
    // 0x15126c: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x15126cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151270: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151270u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151274: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x151274u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151278: 0x81d02  srl         $v1, $t0, 20
    ctx->pc = 0x151278u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x15127c: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x15127cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151280: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151280u;
    {
        const bool branch_taken_0x151280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151280u;
            // 0x151284: 0xae430004  sw          $v1, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151280) {
            ctx->pc = 0x151294u;
            goto label_151294;
        }
    }
    ctx->pc = 0x151288u;
label_151288:
    // 0x151288: 0x81502  srl         $v0, $t0, 20
    ctx->pc = 0x151288u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x15128c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x15128cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151290: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x151290u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
label_151294:
    // 0x151294: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151294u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151298: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151298u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15129c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x15129cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1512a0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1512a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1512a4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1512a4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1512a8: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1512a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1512ac: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1512acu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1512b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1512b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1512b4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1512b4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1512b8: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1512b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1512bc: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1512bcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1512c0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1512c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1512c4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1512c4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1512c8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1512C8u;
    {
        const bool branch_taken_0x1512c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1512CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1512C8u;
            // 0x1512cc: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1512c8) {
            ctx->pc = 0x1512E0u;
            goto label_1512e0;
        }
    }
    ctx->pc = 0x1512D0u;
label_1512d0:
    // 0x1512d0: 0x81502  srl         $v0, $t0, 20
    ctx->pc = 0x1512d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x1512d4: 0x84300  sll         $t0, $t0, 12
    ctx->pc = 0x1512d4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 12));
    // 0x1512d8: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x1512d8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x1512dc: 0x2631000c  addiu       $s1, $s1, 0xC
    ctx->pc = 0x1512dcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
label_1512e0:
    // 0x1512e0: 0x2a220014  slti        $v0, $s1, 0x14
    ctx->pc = 0x1512e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1512e4: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1512E4u;
    {
        const bool branch_taken_0x1512e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1512E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1512E4u;
            // 0x1512e8: 0x81502  srl         $v0, $t0, 20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1512e4) {
            ctx->pc = 0x151360u;
            goto label_151360;
        }
    }
    ctx->pc = 0x1512ECu;
    // 0x1512ec: 0x2631ffec  addiu       $s1, $s1, -0x14
    ctx->pc = 0x1512ecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967276));
    // 0x1512f0: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1512F0u;
    {
        const bool branch_taken_0x1512f0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1512F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1512F0u;
            // 0x1512f4: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1512f0) {
            ctx->pc = 0x151318u;
            goto label_151318;
        }
    }
    ctx->pc = 0x1512F8u;
    // 0x1512f8: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x1512f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1512fc: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1512fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151300: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x151300u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151304: 0x81d02  srl         $v1, $t0, 20
    ctx->pc = 0x151304u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x151308: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x151308u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x15130c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15130Cu;
    {
        const bool branch_taken_0x15130c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15130Cu;
            // 0x151310: 0xae430008  sw          $v1, 0x8($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15130c) {
            ctx->pc = 0x151324u;
            goto label_151324;
        }
    }
    ctx->pc = 0x151314u;
    // 0x151314: 0x0  nop
    ctx->pc = 0x151314u;
    // NOP
label_151318:
    // 0x151318: 0x81502  srl         $v0, $t0, 20
    ctx->pc = 0x151318u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 20));
    // 0x15131c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x15131cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151320: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x151320u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
label_151324:
    // 0x151324: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151324u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151328: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151328u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15132c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x15132cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151330: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151330u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151334: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151334u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151338: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151338u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15133c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15133cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151340: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151340u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151344: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151344u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151348: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151348u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15134c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15134cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151350: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151350u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151354: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151354u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151358: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151358u;
    {
        const bool branch_taken_0x151358 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15135Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151358u;
            // 0x15135c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151358) {
            ctx->pc = 0x15136Cu;
            goto label_15136c;
        }
    }
    ctx->pc = 0x151360u;
label_151360:
    // 0x151360: 0x84300  sll         $t0, $t0, 12
    ctx->pc = 0x151360u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 12));
    // 0x151364: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x151364u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x151368: 0x2631000c  addiu       $s1, $s1, 0xC
    ctx->pc = 0x151368u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
label_15136c:
    // 0x15136c: 0x2a22001c  slti        $v0, $s1, 0x1C
    ctx->pc = 0x15136cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x151370: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151370u;
    {
        const bool branch_taken_0x151370 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151370u;
            // 0x151374: 0x81702  srl         $v0, $t0, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151370) {
            ctx->pc = 0x1513E8u;
            goto label_1513e8;
        }
    }
    ctx->pc = 0x151378u;
    // 0x151378: 0x2631ffe4  addiu       $s1, $s1, -0x1C
    ctx->pc = 0x151378u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967268));
    // 0x15137c: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15137Cu;
    {
        const bool branch_taken_0x15137c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15137Cu;
            // 0x151380: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15137c) {
            ctx->pc = 0x1513A0u;
            goto label_1513a0;
        }
    }
    ctx->pc = 0x151384u;
    // 0x151384: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x151384u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151388: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151388u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x15138c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15138cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151390: 0x81f02  srl         $v1, $t0, 28
    ctx->pc = 0x151390u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x151394: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x151394u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151398: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151398u;
    {
        const bool branch_taken_0x151398 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15139Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151398u;
            // 0x15139c: 0xae43000c  sw          $v1, 0xC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151398) {
            ctx->pc = 0x1513ACu;
            goto label_1513ac;
        }
    }
    ctx->pc = 0x1513A0u;
label_1513a0:
    // 0x1513a0: 0x81702  srl         $v0, $t0, 28
    ctx->pc = 0x1513a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x1513a4: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1513a4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1513a8: 0xae42000c  sw          $v0, 0xC($s2)
    ctx->pc = 0x1513a8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 2));
label_1513ac:
    // 0x1513ac: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x1513acu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1513b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1513b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1513b4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1513b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1513b8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1513b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1513bc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1513bcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1513c0: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1513c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1513c4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1513c4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1513c8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1513c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1513cc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1513ccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1513d0: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1513d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1513d4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1513d4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1513d8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1513d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1513dc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1513dcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1513e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1513E0u;
    {
        const bool branch_taken_0x1513e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1513E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1513E0u;
            // 0x1513e4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1513e0) {
            ctx->pc = 0x1513F4u;
            goto label_1513f4;
        }
    }
    ctx->pc = 0x1513E8u;
label_1513e8:
    // 0x1513e8: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x1513e8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x1513ec: 0xae42000c  sw          $v0, 0xC($s2)
    ctx->pc = 0x1513ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 2));
    // 0x1513f0: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x1513f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_1513f4:
    // 0x1513f4: 0x2a22001c  slti        $v0, $s1, 0x1C
    ctx->pc = 0x1513f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x1513f8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1513F8u;
    {
        const bool branch_taken_0x1513f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1513FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1513F8u;
            // 0x1513fc: 0x81702  srl         $v0, $t0, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1513f8) {
            ctx->pc = 0x151470u;
            goto label_151470;
        }
    }
    ctx->pc = 0x151400u;
    // 0x151400: 0x2631ffe4  addiu       $s1, $s1, -0x1C
    ctx->pc = 0x151400u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967268));
    // 0x151404: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x151404u;
    {
        const bool branch_taken_0x151404 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151404u;
            // 0x151408: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151404) {
            ctx->pc = 0x151428u;
            goto label_151428;
        }
    }
    ctx->pc = 0x15140Cu;
    // 0x15140c: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x15140cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151410: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151410u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151414: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x151414u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151418: 0x81f02  srl         $v1, $t0, 28
    ctx->pc = 0x151418u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x15141c: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x15141cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151420: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151420u;
    {
        const bool branch_taken_0x151420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151420u;
            // 0x151424: 0xae430010  sw          $v1, 0x10($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151420) {
            ctx->pc = 0x151434u;
            goto label_151434;
        }
    }
    ctx->pc = 0x151428u;
label_151428:
    // 0x151428: 0x81702  srl         $v0, $t0, 28
    ctx->pc = 0x151428u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 28));
    // 0x15142c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x15142cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151430: 0xae420010  sw          $v0, 0x10($s2)
    ctx->pc = 0x151430u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
label_151434:
    // 0x151434: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151434u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151438: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151438u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15143c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x15143cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151440: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151440u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151444: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151444u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151448: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151448u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15144c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15144cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151450: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151450u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151454: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151454u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151458: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151458u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15145c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15145cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151460: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151460u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151464: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151464u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151468: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151468u;
    {
        const bool branch_taken_0x151468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15146Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151468u;
            // 0x15146c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151468) {
            ctx->pc = 0x15147Cu;
            goto label_15147c;
        }
    }
    ctx->pc = 0x151470u;
label_151470:
    // 0x151470: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x151470u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x151474: 0xae420010  sw          $v0, 0x10($s2)
    ctx->pc = 0x151474u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x151478: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x151478u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_15147c:
    // 0x15147c: 0x2a22000e  slti        $v0, $s1, 0xE
    ctx->pc = 0x15147cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)14) ? 1 : 0);
    // 0x151480: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151480u;
    {
        const bool branch_taken_0x151480 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151480u;
            // 0x151484: 0x81382  srl         $v0, $t0, 14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151480) {
            ctx->pc = 0x1514F8u;
            goto label_1514f8;
        }
    }
    ctx->pc = 0x151488u;
    // 0x151488: 0x2631fff2  addiu       $s1, $s1, -0xE
    ctx->pc = 0x151488u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967282));
    // 0x15148c: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15148Cu;
    {
        const bool branch_taken_0x15148c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15148Cu;
            // 0x151490: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15148c) {
            ctx->pc = 0x1514B0u;
            goto label_1514b0;
        }
    }
    ctx->pc = 0x151494u;
    // 0x151494: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x151494u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151498: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151498u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x15149c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15149cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1514a0: 0x81b82  srl         $v1, $t0, 14
    ctx->pc = 0x1514a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 14));
    // 0x1514a4: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x1514a4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x1514a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1514A8u;
    {
        const bool branch_taken_0x1514a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1514ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1514A8u;
            // 0x1514ac: 0xae430014  sw          $v1, 0x14($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1514a8) {
            ctx->pc = 0x1514BCu;
            goto label_1514bc;
        }
    }
    ctx->pc = 0x1514B0u;
label_1514b0:
    // 0x1514b0: 0x81382  srl         $v0, $t0, 14
    ctx->pc = 0x1514b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 14));
    // 0x1514b4: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1514b4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1514b8: 0xae420014  sw          $v0, 0x14($s2)
    ctx->pc = 0x1514b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
label_1514bc:
    // 0x1514bc: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x1514bcu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1514c0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1514c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1514c4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1514c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1514c8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1514c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1514cc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1514ccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1514d0: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1514d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1514d4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1514d4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1514d8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1514d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1514dc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1514dcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1514e0: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1514e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1514e4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1514e4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1514e8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1514e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1514ec: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1514ecu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1514f0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1514F0u;
    {
        const bool branch_taken_0x1514f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1514F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1514F0u;
            // 0x1514f4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1514f0) {
            ctx->pc = 0x151504u;
            goto label_151504;
        }
    }
    ctx->pc = 0x1514F8u;
label_1514f8:
    // 0x1514f8: 0x84480  sll         $t0, $t0, 18
    ctx->pc = 0x1514f8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 18));
    // 0x1514fc: 0xae420014  sw          $v0, 0x14($s2)
    ctx->pc = 0x1514fcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x151500: 0x26310012  addiu       $s1, $s1, 0x12
    ctx->pc = 0x151500u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 18));
label_151504:
    // 0x151504: 0x2a22001f  slti        $v0, $s1, 0x1F
    ctx->pc = 0x151504u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x151508: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151508u;
    {
        const bool branch_taken_0x151508 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15150Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151508u;
            // 0x15150c: 0x817c2  srl         $v0, $t0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151508) {
            ctx->pc = 0x151580u;
            goto label_151580;
        }
    }
    ctx->pc = 0x151510u;
    // 0x151510: 0x2631ffe1  addiu       $s1, $s1, -0x1F
    ctx->pc = 0x151510u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967265));
    // 0x151514: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x151514u;
    {
        const bool branch_taken_0x151514 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151514u;
            // 0x151518: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151514) {
            ctx->pc = 0x151538u;
            goto label_151538;
        }
    }
    ctx->pc = 0x15151Cu;
    // 0x15151c: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x15151cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151520: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151520u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151524: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x151524u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151528: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x151528u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x15152c: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x15152cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151530: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151530u;
    {
        const bool branch_taken_0x151530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151530u;
            // 0x151534: 0xae430018  sw          $v1, 0x18($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151530) {
            ctx->pc = 0x151544u;
            goto label_151544;
        }
    }
    ctx->pc = 0x151538u;
label_151538:
    // 0x151538: 0x817c2  srl         $v0, $t0, 31
    ctx->pc = 0x151538u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x15153c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x15153cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151540: 0xae420018  sw          $v0, 0x18($s2)
    ctx->pc = 0x151540u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
label_151544:
    // 0x151544: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151544u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151548: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151548u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15154c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x15154cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151550: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151550u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151554: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151554u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151558: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151558u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15155c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15155cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151560: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151560u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151564: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151564u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151568: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151568u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15156c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15156cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151570: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151570u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151574: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151574u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151578: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151578u;
    {
        const bool branch_taken_0x151578 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15157Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151578u;
            // 0x15157c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151578) {
            ctx->pc = 0x15158Cu;
            goto label_15158c;
        }
    }
    ctx->pc = 0x151580u;
label_151580:
    // 0x151580: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x151580u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x151584: 0xae420018  sw          $v0, 0x18($s2)
    ctx->pc = 0x151584u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
    // 0x151588: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151588u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_15158c:
    // 0x15158c: 0x2a220016  slti        $v0, $s1, 0x16
    ctx->pc = 0x15158cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x151590: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151590u;
    {
        const bool branch_taken_0x151590 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151590u;
            // 0x151594: 0x81582  srl         $v0, $t0, 22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151590) {
            ctx->pc = 0x151608u;
            goto label_151608;
        }
    }
    ctx->pc = 0x151598u;
    // 0x151598: 0x2631ffea  addiu       $s1, $s1, -0x16
    ctx->pc = 0x151598u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967274));
    // 0x15159c: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15159Cu;
    {
        const bool branch_taken_0x15159c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1515A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15159Cu;
            // 0x1515a0: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15159c) {
            ctx->pc = 0x1515C0u;
            goto label_1515c0;
        }
    }
    ctx->pc = 0x1515A4u;
    // 0x1515a4: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x1515a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1515a8: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1515a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1515ac: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1515acu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1515b0: 0x81d82  srl         $v1, $t0, 22
    ctx->pc = 0x1515b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 22));
    // 0x1515b4: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x1515b4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x1515b8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1515B8u;
    {
        const bool branch_taken_0x1515b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1515BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1515B8u;
            // 0x1515bc: 0xae43001c  sw          $v1, 0x1C($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1515b8) {
            ctx->pc = 0x1515CCu;
            goto label_1515cc;
        }
    }
    ctx->pc = 0x1515C0u;
label_1515c0:
    // 0x1515c0: 0x81582  srl         $v0, $t0, 22
    ctx->pc = 0x1515c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 22));
    // 0x1515c4: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1515c4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1515c8: 0xae42001c  sw          $v0, 0x1C($s2)
    ctx->pc = 0x1515c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 2));
label_1515cc:
    // 0x1515cc: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x1515ccu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1515d0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1515d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1515d4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1515d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1515d8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1515d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1515dc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1515dcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1515e0: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1515e0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1515e4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1515e4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1515e8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1515e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1515ec: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1515ecu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1515f0: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1515f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1515f4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1515f4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1515f8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1515f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1515fc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1515fcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151600: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151600u;
    {
        const bool branch_taken_0x151600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151600u;
            // 0x151604: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151600) {
            ctx->pc = 0x151614u;
            goto label_151614;
        }
    }
    ctx->pc = 0x151608u;
label_151608:
    // 0x151608: 0x84280  sll         $t0, $t0, 10
    ctx->pc = 0x151608u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 10));
    // 0x15160c: 0xae42001c  sw          $v0, 0x1C($s2)
    ctx->pc = 0x15160cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 2));
    // 0x151610: 0x2631000a  addiu       $s1, $s1, 0xA
    ctx->pc = 0x151610u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 10));
label_151614:
    // 0x151614: 0x2a22001f  slti        $v0, $s1, 0x1F
    ctx->pc = 0x151614u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x151618: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x151618u;
    {
        const bool branch_taken_0x151618 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15161Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151618u;
            // 0x15161c: 0x817c2  srl         $v0, $t0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151618) {
            ctx->pc = 0x151690u;
            goto label_151690;
        }
    }
    ctx->pc = 0x151620u;
    // 0x151620: 0x2631ffe1  addiu       $s1, $s1, -0x1F
    ctx->pc = 0x151620u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967265));
    // 0x151624: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x151624u;
    {
        const bool branch_taken_0x151624 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151624u;
            // 0x151628: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151624) {
            ctx->pc = 0x151648u;
            goto label_151648;
        }
    }
    ctx->pc = 0x15162Cu;
    // 0x15162c: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x15162cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151630: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151630u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151634: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x151634u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151638: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x151638u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x15163c: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x15163cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151640: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151640u;
    {
        const bool branch_taken_0x151640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151640u;
            // 0x151644: 0xae430020  sw          $v1, 0x20($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151640) {
            ctx->pc = 0x151654u;
            goto label_151654;
        }
    }
    ctx->pc = 0x151648u;
label_151648:
    // 0x151648: 0x817c2  srl         $v0, $t0, 31
    ctx->pc = 0x151648u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x15164c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x15164cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151650: 0xae420020  sw          $v0, 0x20($s2)
    ctx->pc = 0x151650u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 2));
label_151654:
    // 0x151654: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151654u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151658: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151658u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15165c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x15165cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151660: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151660u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151664: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151664u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151668: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151668u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15166c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15166cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151670: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151670u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151674: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151674u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151678: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151678u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15167c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15167cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151680: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151680u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151684: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151684u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151688: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151688u;
    {
        const bool branch_taken_0x151688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15168Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151688u;
            // 0x15168c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151688) {
            ctx->pc = 0x15169Cu;
            goto label_15169c;
        }
    }
    ctx->pc = 0x151690u;
label_151690:
    // 0x151690: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x151690u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x151694: 0xae420020  sw          $v0, 0x20($s2)
    ctx->pc = 0x151694u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 2));
    // 0x151698: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151698u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_15169c:
    // 0x15169c: 0x2a22001f  slti        $v0, $s1, 0x1F
    ctx->pc = 0x15169cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1516a0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1516A0u;
    {
        const bool branch_taken_0x1516a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1516A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1516A0u;
            // 0x1516a4: 0x817c2  srl         $v0, $t0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1516a0) {
            ctx->pc = 0x151718u;
            goto label_151718;
        }
    }
    ctx->pc = 0x1516A8u;
    // 0x1516a8: 0x2631ffe1  addiu       $s1, $s1, -0x1F
    ctx->pc = 0x1516a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967265));
    // 0x1516ac: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1516ACu;
    {
        const bool branch_taken_0x1516ac = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1516B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1516ACu;
            // 0x1516b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1516ac) {
            ctx->pc = 0x1516D0u;
            goto label_1516d0;
        }
    }
    ctx->pc = 0x1516B4u;
    // 0x1516b4: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x1516b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1516b8: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1516b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1516bc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1516bcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1516c0: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x1516c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x1516c4: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x1516c4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x1516c8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1516C8u;
    {
        const bool branch_taken_0x1516c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1516CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1516C8u;
            // 0x1516cc: 0xae430024  sw          $v1, 0x24($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1516c8) {
            ctx->pc = 0x1516DCu;
            goto label_1516dc;
        }
    }
    ctx->pc = 0x1516D0u;
label_1516d0:
    // 0x1516d0: 0x817c2  srl         $v0, $t0, 31
    ctx->pc = 0x1516d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x1516d4: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1516d4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1516d8: 0xae420024  sw          $v0, 0x24($s2)
    ctx->pc = 0x1516d8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
label_1516dc:
    // 0x1516dc: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x1516dcu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1516e0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1516e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1516e4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1516e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1516e8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1516e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1516ec: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1516ecu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1516f0: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1516f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1516f4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1516f4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1516f8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1516f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1516fc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1516fcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151700: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151700u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151704: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x151704u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151708: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151708u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15170c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15170cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151710: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x151710u;
    {
        const bool branch_taken_0x151710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151710u;
            // 0x151714: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151710) {
            ctx->pc = 0x151724u;
            goto label_151724;
        }
    }
    ctx->pc = 0x151718u;
label_151718:
    // 0x151718: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x151718u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x15171c: 0xae420024  sw          $v0, 0x24($s2)
    ctx->pc = 0x15171cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
    // 0x151720: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x151720u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_151724:
    // 0x151724: 0x8e420024  lw          $v0, 0x24($s2)
    ctx->pc = 0x151724u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
    // 0x151728: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x151728u;
    {
        const bool branch_taken_0x151728 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15172Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151728u;
            // 0x15172c: 0x2a22001f  slti        $v0, $s1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x151728) {
            ctx->pc = 0x151794u;
            goto label_151794;
        }
    }
    ctx->pc = 0x151730u;
    // 0x151730: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x151730u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x151734: 0x26310008  addiu       $s1, $s1, 0x8
    ctx->pc = 0x151734u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
label_151738:
    // 0x151738: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x151738u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15173c: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x15173Cu;
    {
        const bool branch_taken_0x15173c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15173c) {
            ctx->pc = 0x151740u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15173Cu;
            // 0x151740: 0x84200  sll         $t0, $t0, 8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x151784u;
            goto label_151784;
        }
    }
    ctx->pc = 0x151744u;
    // 0x151744: 0x2631ffe0  addiu       $s1, $s1, -0x20
    ctx->pc = 0x151744u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967264));
    // 0x151748: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x151748u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x15174c: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x15174cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151750: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151750u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151754: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151754u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151758: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151758u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15175c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15175cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151760: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151760u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151764: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151764u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151768: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151768u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15176c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15176cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151770: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151770u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151774: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x151774u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151778: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151778u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x15177c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15177cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151780: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151780u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_151784:
    // 0x151784: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x151784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x151788: 0x483ffeb  bgezl       $a0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x151788u;
    {
        const bool branch_taken_0x151788 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x151788) {
            ctx->pc = 0x15178Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151788u;
            // 0x15178c: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x151738u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_151738;
        }
    }
    ctx->pc = 0x151790u;
    // 0x151790: 0x2a22001f  slti        $v0, $s1, 0x1F
    ctx->pc = 0x151790u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)31) ? 1 : 0);
label_151794:
    // 0x151794: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x151794u;
    {
        const bool branch_taken_0x151794 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151794u;
            // 0x151798: 0x817c2  srl         $v0, $t0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151794) {
            ctx->pc = 0x1517D0u;
            goto label_1517d0;
        }
    }
    ctx->pc = 0x15179Cu;
    // 0x15179c: 0x2631ffe1  addiu       $s1, $s1, -0x1F
    ctx->pc = 0x15179cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967265));
    // 0x1517a0: 0x12200007  beqz        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1517A0u;
    {
        const bool branch_taken_0x1517a0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1517A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1517A0u;
            // 0x1517a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1517a0) {
            ctx->pc = 0x1517C0u;
            goto label_1517c0;
        }
    }
    ctx->pc = 0x1517A8u;
    // 0x1517a8: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x1517a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1517ac: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1517acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1517b0: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1517b0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1517b4: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x1517b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x1517b8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1517B8u;
    {
        const bool branch_taken_0x1517b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1517BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1517B8u;
            // 0x1517bc: 0xae430028  sw          $v1, 0x28($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 40), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1517b8) {
            ctx->pc = 0x1517C8u;
            goto label_1517c8;
        }
    }
    ctx->pc = 0x1517C0u;
label_1517c0:
    // 0x1517c0: 0x817c2  srl         $v0, $t0, 31
    ctx->pc = 0x1517c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x1517c4: 0xae420028  sw          $v0, 0x28($s2)
    ctx->pc = 0x1517c4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 40), GPR_U32(ctx, 2));
label_1517c8:
    // 0x1517c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1517C8u;
    {
        const bool branch_taken_0x1517c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1517CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1517C8u;
            // 0x1517cc: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1517c8) {
            ctx->pc = 0x1517D8u;
            goto label_1517d8;
        }
    }
    ctx->pc = 0x1517D0u;
label_1517d0:
    // 0x1517d0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1517d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1517d4: 0xae420028  sw          $v0, 0x28($s2)
    ctx->pc = 0x1517d4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 40), GPR_U32(ctx, 2));
label_1517d8:
    // 0x1517d8: 0x8e420028  lw          $v0, 0x28($s2)
    ctx->pc = 0x1517d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x1517dc: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1517DCu;
    {
        const bool branch_taken_0x1517dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1517E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1517DCu;
            // 0x1517e0: 0x2403003f  addiu       $v1, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1517dc) {
            ctx->pc = 0x15180Cu;
            goto label_15180c;
        }
    }
    ctx->pc = 0x1517E4u;
    // 0x1517e4: 0x26310008  addiu       $s1, $s1, 0x8
    ctx->pc = 0x1517e4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
label_1517e8:
    // 0x1517e8: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x1517e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1517ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1517ECu;
    {
        const bool branch_taken_0x1517ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1517F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1517ECu;
            // 0x1517f0: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1517ec) {
            ctx->pc = 0x1517FCu;
            goto label_1517fc;
        }
    }
    ctx->pc = 0x1517F4u;
    // 0x1517f4: 0x2631ffe0  addiu       $s1, $s1, -0x20
    ctx->pc = 0x1517f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967264));
    // 0x1517f8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1517f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
label_1517fc:
    // 0x1517fc: 0x0  nop
    ctx->pc = 0x1517fcu;
    // NOP
    // 0x151800: 0x0  nop
    ctx->pc = 0x151800u;
    // NOP
    // 0x151804: 0x463fff8  bgezl       $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x151804u;
    {
        const bool branch_taken_0x151804 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x151804) {
            ctx->pc = 0x151808u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151804u;
            // 0x151808: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1517E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1517e8;
        }
    }
    ctx->pc = 0x15180Cu;
label_15180c:
    // 0x15180c: 0xc054382  jal         func_150E08
    ctx->pc = 0x15180Cu;
    SET_GPR_U32(ctx, 31, 0x151814u);
    ctx->pc = 0x151810u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15180Cu;
            // 0x151810: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150E08u;
    if (runtime->hasFunction(0x150E08u)) {
        auto targetFn = runtime->lookupFunction(0x150E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151814u; }
        if (ctx->pc != 0x151814u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150E08_0x150e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151814u; }
        if (ctx->pc != 0x151814u) { return; }
    }
    ctx->pc = 0x151814u;
label_151814:
    // 0x151814: 0xc0543b4  jal         func_150ED0
    ctx->pc = 0x151814u;
    SET_GPR_U32(ctx, 31, 0x15181Cu);
    ctx->pc = 0x151818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x151814u;
            // 0x151818: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150ED0u;
    if (runtime->hasFunction(0x150ED0u)) {
        auto targetFn = runtime->lookupFunction(0x150ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15181Cu; }
        if (ctx->pc != 0x15181Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150ED0_0x150ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15181Cu; }
        if (ctx->pc != 0x15181Cu) { return; }
    }
    ctx->pc = 0x15181Cu;
label_15181c:
    // 0x15181c: 0xc05444c  jal         func_151130
    ctx->pc = 0x15181Cu;
    SET_GPR_U32(ctx, 31, 0x151824u);
    ctx->pc = 0x151820u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15181Cu;
            // 0x151820: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151130u;
    if (runtime->hasFunction(0x151130u)) {
        auto targetFn = runtime->lookupFunction(0x151130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151824u; }
        if (ctx->pc != 0x151824u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151130_0x151130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151824u; }
        if (ctx->pc != 0x151824u) { return; }
    }
    ctx->pc = 0x151824u;
label_151824:
    // 0x151824: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x151824u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x151828: 0x2131823  subu        $v1, $s0, $s3
    ctx->pc = 0x151828u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x15182c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15182cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x151830: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x151830u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x151834: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x151834u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x151838: 0x2231821  addu        $v1, $s1, $v1
    ctx->pc = 0x151838u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x15183c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15183cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x151840: 0xae42032c  sw          $v0, 0x32C($s2)
    ctx->pc = 0x151840u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 812), GPR_U32(ctx, 2));
    // 0x151844: 0x2462ffc7  addiu       $v0, $v1, -0x39
    ctx->pc = 0x151844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967239));
    // 0x151848: 0xae440328  sw          $a0, 0x328($s2)
    ctx->pc = 0x151848u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 808), GPR_U32(ctx, 4));
    // 0x15184c: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x15184cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x151850: 0x2463ffce  addiu       $v1, $v1, -0x32
    ctx->pc = 0x151850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967246));
    // 0x151854: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x151854u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x151858: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x151858u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x15185c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15185cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x151860: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x151860u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x151864: 0x2621021  addu        $v0, $s3, $v0
    ctx->pc = 0x151864u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x151868: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x151868u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15186c: 0x3e00008  jr          $ra
    ctx->pc = 0x15186Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x151870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15186Cu;
            // 0x151870: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151174u: goto label_151174;
            case 0x151218u: goto label_151218;
            case 0x151220u: goto label_151220;
            case 0x151288u: goto label_151288;
            case 0x151294u: goto label_151294;
            case 0x1512D0u: goto label_1512d0;
            case 0x1512E0u: goto label_1512e0;
            case 0x151318u: goto label_151318;
            case 0x151324u: goto label_151324;
            case 0x151360u: goto label_151360;
            case 0x15136Cu: goto label_15136c;
            case 0x1513A0u: goto label_1513a0;
            case 0x1513ACu: goto label_1513ac;
            case 0x1513E8u: goto label_1513e8;
            case 0x1513F4u: goto label_1513f4;
            case 0x151428u: goto label_151428;
            case 0x151434u: goto label_151434;
            case 0x151470u: goto label_151470;
            case 0x15147Cu: goto label_15147c;
            case 0x1514B0u: goto label_1514b0;
            case 0x1514BCu: goto label_1514bc;
            case 0x1514F8u: goto label_1514f8;
            case 0x151504u: goto label_151504;
            case 0x151538u: goto label_151538;
            case 0x151544u: goto label_151544;
            case 0x151580u: goto label_151580;
            case 0x15158Cu: goto label_15158c;
            case 0x1515C0u: goto label_1515c0;
            case 0x1515CCu: goto label_1515cc;
            case 0x151608u: goto label_151608;
            case 0x151614u: goto label_151614;
            case 0x151648u: goto label_151648;
            case 0x151654u: goto label_151654;
            case 0x151690u: goto label_151690;
            case 0x15169Cu: goto label_15169c;
            case 0x1516D0u: goto label_1516d0;
            case 0x1516DCu: goto label_1516dc;
            case 0x151718u: goto label_151718;
            case 0x151724u: goto label_151724;
            case 0x151738u: goto label_151738;
            case 0x151784u: goto label_151784;
            case 0x151794u: goto label_151794;
            case 0x1517C0u: goto label_1517c0;
            case 0x1517C8u: goto label_1517c8;
            case 0x1517D0u: goto label_1517d0;
            case 0x1517D8u: goto label_1517d8;
            case 0x1517E8u: goto label_1517e8;
            case 0x1517FCu: goto label_1517fc;
            case 0x15180Cu: goto label_15180c;
            case 0x151814u: goto label_151814;
            case 0x15181Cu: goto label_15181c;
            case 0x151824u: goto label_151824;
            default: break;
        }
        return;
    }
    ctx->pc = 0x151874u;
    // 0x151874: 0x0  nop
    ctx->pc = 0x151874u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
