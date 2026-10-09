#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001551A8
// Address: 0x1551a8 - 0x155800
void sub_001551A8_0x1551a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001551A8_0x1551a8");
#endif

    switch (ctx->pc) {
        case 0x155698u: goto label_155698;
        default: break;
    }

    ctx->pc = 0x1551a8u;

    // 0x1551a8: 0x248b0128  addiu       $t3, $a0, 0x128
    ctx->pc = 0x1551a8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x1551ac: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1551acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1551b0: 0x8d6304f8  lw          $v1, 0x4F8($t3)
    ctx->pc = 0x1551b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 1272)));
    // 0x1551b4: 0xa0602d  daddu       $t4, $a1, $zero
    ctx->pc = 0x1551b4u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1551b8: 0xad6404dc  sw          $a0, 0x4DC($t3)
    ctx->pc = 0x1551b8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 1244), GPR_U32(ctx, 4));
    // 0x1551bc: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1551bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1551c0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1551c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1551c4: 0x1824024  and         $t0, $t4, $v0
    ctx->pc = 0x1551c4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 12) & GPR_U64(ctx, 2));
    // 0x1551c8: 0xad6304f8  sw          $v1, 0x4F8($t3)
    ctx->pc = 0x1551c8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 1272), GPR_U32(ctx, 3));
    // 0x1551cc: 0x1881023  subu        $v0, $t4, $t0
    ctx->pc = 0x1551ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 12), GPR_U32(ctx, 8)));
    // 0x1551d0: 0x250c0  sll         $t2, $v0, 3
    ctx->pc = 0x1551d0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1551d4: 0x81090000  lb          $t1, 0x0($t0)
    ctx->pc = 0x1551d4u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1551d8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1551d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1551dc: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1551dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1551e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1551e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1551e4: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x1551e4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1551e8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1551e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1551ec: 0x91050000  lbu         $a1, 0x0($t0)
    ctx->pc = 0x1551ecu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1551f0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1551f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1551f4: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x1551f4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1551f8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1551f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1551fc: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1551fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155200: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155200u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155204: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x155204u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x155208: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155208u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x15520c: 0x1234825  or          $t1, $t1, $v1
    ctx->pc = 0x15520cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 3));
    // 0x155210: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155210u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155214: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x155214u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155218: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x155218u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x15521c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15521cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155220: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155220u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155224: 0x1244825  or          $t1, $t1, $a0
    ctx->pc = 0x155224u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 4));
    // 0x155228: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155228u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15522c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15522cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155230: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x155230u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x155234: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155234u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155238: 0x1254825  or          $t1, $t1, $a1
    ctx->pc = 0x155238u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 5));
    // 0x15523c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15523cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155240: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x155240u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155244: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x155244u;
    {
        const bool branch_taken_0x155244 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x155248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155244u;
            // 0x155248: 0x1494804  sllv        $t1, $t1, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 10) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155244) {
            ctx->pc = 0x155268u;
            goto label_155268;
        }
    }
    ctx->pc = 0x15524Cu;
    // 0x15524c: 0xa1023  negu        $v0, $t2
    ctx->pc = 0x15524cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 10)));
    // 0x155250: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x155250u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155254: 0x1221025  or          $v0, $t1, $v0
    ctx->pc = 0x155254u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x155258: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x155258u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x15525c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15525Cu;
    {
        const bool branch_taken_0x15525c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15525Cu;
            // 0x155260: 0xad6200d8  sw          $v0, 0xD8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 216), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15525c) {
            ctx->pc = 0x155270u;
            goto label_155270;
        }
    }
    ctx->pc = 0x155264u;
    // 0x155264: 0x0  nop
    ctx->pc = 0x155264u;
    // NOP
label_155268:
    // 0x155268: 0xad6900d8  sw          $t1, 0xD8($t3)
    ctx->pc = 0x155268u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 216), GPR_U32(ctx, 9));
    // 0x15526c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x15526cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_155270:
    // 0x155270: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x155270u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155274: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155274u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155278: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155278u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15527c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15527cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155280: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155280u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155284: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155284u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155288: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x155288u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15528c: 0x29420016  slti        $v0, $t2, 0x16
    ctx->pc = 0x15528cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x155290: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155290u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155294: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155294u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155298: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x155298u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15529c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15529cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1552a0: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1552a0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1552a4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1552a4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1552a8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1552A8u;
    {
        const bool branch_taken_0x1552a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1552ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1552A8u;
            // 0x1552ac: 0xe43825  or          $a3, $a3, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1552a8) {
            ctx->pc = 0x155320u;
            goto label_155320;
        }
    }
    ctx->pc = 0x1552B0u;
    // 0x1552b0: 0x254affea  addiu       $t2, $t2, -0x16
    ctx->pc = 0x1552b0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967274));
    // 0x1552b4: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1552B4u;
    {
        const bool branch_taken_0x1552b4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1552B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1552B4u;
            // 0x1552b8: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1552b4) {
            ctx->pc = 0x1552D8u;
            goto label_1552d8;
        }
    }
    ctx->pc = 0x1552BCu;
    // 0x1552bc: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x1552bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1552c0: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1552c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1552c4: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x1552c4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x1552c8: 0x91d82  srl         $v1, $t1, 22
    ctx->pc = 0x1552c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 22));
    // 0x1552cc: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x1552ccu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x1552d0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1552D0u;
    {
        const bool branch_taken_0x1552d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1552D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1552D0u;
            // 0x1552d4: 0xad6300dc  sw          $v1, 0xDC($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 220), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1552d0) {
            ctx->pc = 0x1552E4u;
            goto label_1552e4;
        }
    }
    ctx->pc = 0x1552D8u;
label_1552d8:
    // 0x1552d8: 0x91582  srl         $v0, $t1, 22
    ctx->pc = 0x1552d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 22));
    // 0x1552dc: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1552dcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1552e0: 0xad6200dc  sw          $v0, 0xDC($t3)
    ctx->pc = 0x1552e0u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 220), GPR_U32(ctx, 2));
label_1552e4:
    // 0x1552e4: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x1552e4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1552e8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1552e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1552ec: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1552ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1552f0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1552f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1552f4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1552f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1552f8: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1552f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1552fc: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1552fcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155300: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155300u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155304: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155304u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155308: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155308u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15530c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15530cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155310: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155310u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155314: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155314u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155318: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x155318u;
    {
        const bool branch_taken_0x155318 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15531Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155318u;
            // 0x15531c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155318) {
            ctx->pc = 0x155330u;
            goto label_155330;
        }
    }
    ctx->pc = 0x155320u;
label_155320:
    // 0x155320: 0x91582  srl         $v0, $t1, 22
    ctx->pc = 0x155320u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 22));
    // 0x155324: 0x94a80  sll         $t1, $t1, 10
    ctx->pc = 0x155324u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 10));
    // 0x155328: 0xad6200dc  sw          $v0, 0xDC($t3)
    ctx->pc = 0x155328u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 220), GPR_U32(ctx, 2));
    // 0x15532c: 0x254a000a  addiu       $t2, $t2, 0xA
    ctx->pc = 0x15532cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 10));
label_155330:
    // 0x155330: 0x2942001d  slti        $v0, $t2, 0x1D
    ctx->pc = 0x155330u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x155334: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x155334u;
    {
        const bool branch_taken_0x155334 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155334u;
            // 0x155338: 0x91742  srl         $v0, $t1, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155334) {
            ctx->pc = 0x1553B0u;
            goto label_1553b0;
        }
    }
    ctx->pc = 0x15533Cu;
    // 0x15533c: 0x254affe3  addiu       $t2, $t2, -0x1D
    ctx->pc = 0x15533cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967267));
    // 0x155340: 0x11400009  beqz        $t2, . + 4 + (0x9 << 2)
    ctx->pc = 0x155340u;
    {
        const bool branch_taken_0x155340 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x155344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155340u;
            // 0x155344: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155340) {
            ctx->pc = 0x155368u;
            goto label_155368;
        }
    }
    ctx->pc = 0x155348u;
    // 0x155348: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x155348u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x15534c: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x15534cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155350: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x155350u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x155354: 0x91f42  srl         $v1, $t1, 29
    ctx->pc = 0x155354u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
    // 0x155358: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x155358u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x15535c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15535Cu;
    {
        const bool branch_taken_0x15535c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15535Cu;
            // 0x155360: 0xad6300e0  sw          $v1, 0xE0($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 224), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15535c) {
            ctx->pc = 0x155374u;
            goto label_155374;
        }
    }
    ctx->pc = 0x155364u;
    // 0x155364: 0x0  nop
    ctx->pc = 0x155364u;
    // NOP
label_155368:
    // 0x155368: 0x91742  srl         $v0, $t1, 29
    ctx->pc = 0x155368u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
    // 0x15536c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x15536cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155370: 0xad6200e0  sw          $v0, 0xE0($t3)
    ctx->pc = 0x155370u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 224), GPR_U32(ctx, 2));
label_155374:
    // 0x155374: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x155374u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155378: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155378u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15537c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15537cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155380: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155380u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155384: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155384u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155388: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155388u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15538c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15538cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155390: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155390u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155394: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155394u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155398: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155398u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15539c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15539cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1553a0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1553a0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1553a4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1553a4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1553a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1553A8u;
    {
        const bool branch_taken_0x1553a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1553ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1553A8u;
            // 0x1553ac: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1553a8) {
            ctx->pc = 0x1553BCu;
            goto label_1553bc;
        }
    }
    ctx->pc = 0x1553B0u;
label_1553b0:
    // 0x1553b0: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x1553b0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x1553b4: 0xad6200e0  sw          $v0, 0xE0($t3)
    ctx->pc = 0x1553b4u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 224), GPR_U32(ctx, 2));
    // 0x1553b8: 0x254a0003  addiu       $t2, $t2, 0x3
    ctx->pc = 0x1553b8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 3));
label_1553bc:
    // 0x1553bc: 0x29420010  slti        $v0, $t2, 0x10
    ctx->pc = 0x1553bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1553c0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1553C0u;
    {
        const bool branch_taken_0x1553c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1553C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1553C0u;
            // 0x1553c4: 0x91402  srl         $v0, $t1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1553c0) {
            ctx->pc = 0x155438u;
            goto label_155438;
        }
    }
    ctx->pc = 0x1553C8u;
    // 0x1553c8: 0x254afff0  addiu       $t2, $t2, -0x10
    ctx->pc = 0x1553c8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967280));
    // 0x1553cc: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1553CCu;
    {
        const bool branch_taken_0x1553cc = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1553D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1553CCu;
            // 0x1553d0: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1553cc) {
            ctx->pc = 0x1553F0u;
            goto label_1553f0;
        }
    }
    ctx->pc = 0x1553D4u;
    // 0x1553d4: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x1553d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1553d8: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1553d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1553dc: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x1553dcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x1553e0: 0x91c02  srl         $v1, $t1, 16
    ctx->pc = 0x1553e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x1553e4: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x1553e4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x1553e8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1553E8u;
    {
        const bool branch_taken_0x1553e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1553ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1553E8u;
            // 0x1553ec: 0xad6300e4  sw          $v1, 0xE4($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 228), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1553e8) {
            ctx->pc = 0x1553FCu;
            goto label_1553fc;
        }
    }
    ctx->pc = 0x1553F0u;
label_1553f0:
    // 0x1553f0: 0x91402  srl         $v0, $t1, 16
    ctx->pc = 0x1553f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x1553f4: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1553f4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1553f8: 0xad6200e4  sw          $v0, 0xE4($t3)
    ctx->pc = 0x1553f8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 228), GPR_U32(ctx, 2));
label_1553fc:
    // 0x1553fc: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x1553fcu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155400: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155400u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155404: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155404u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155408: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155408u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15540c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15540cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155410: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155410u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155414: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x155414u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155418: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155418u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15541c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15541cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155420: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155420u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155424: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x155424u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155428: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155428u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15542c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15542cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155430: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155430u;
    {
        const bool branch_taken_0x155430 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155430u;
            // 0x155434: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155430) {
            ctx->pc = 0x155444u;
            goto label_155444;
        }
    }
    ctx->pc = 0x155438u;
label_155438:
    // 0x155438: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x155438u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x15543c: 0xad6200e4  sw          $v0, 0xE4($t3)
    ctx->pc = 0x15543cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 228), GPR_U32(ctx, 2));
    // 0x155440: 0x254a0010  addiu       $t2, $t2, 0x10
    ctx->pc = 0x155440u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 16));
label_155444:
    // 0x155444: 0x8d6600e0  lw          $a2, 0xE0($t3)
    ctx->pc = 0x155444u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 224)));
    // 0x155448: 0x24c2fffe  addiu       $v0, $a2, -0x2
    ctx->pc = 0x155448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967294));
    // 0x15544c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x15544cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x155450: 0x10400047  beqz        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x155450u;
    {
        const bool branch_taken_0x155450 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x155454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155450u;
            // 0x155454: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155450) {
            ctx->pc = 0x155570u;
            goto label_155570;
        }
    }
    ctx->pc = 0x155458u;
    // 0x155458: 0x2942001f  slti        $v0, $t2, 0x1F
    ctx->pc = 0x155458u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x15545c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15545Cu;
    {
        const bool branch_taken_0x15545c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15545Cu;
            // 0x155460: 0x917c2  srl         $v0, $t1, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15545c) {
            ctx->pc = 0x1554D8u;
            goto label_1554d8;
        }
    }
    ctx->pc = 0x155464u;
    // 0x155464: 0x254affe1  addiu       $t2, $t2, -0x1F
    ctx->pc = 0x155464u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967265));
    // 0x155468: 0x11400009  beqz        $t2, . + 4 + (0x9 << 2)
    ctx->pc = 0x155468u;
    {
        const bool branch_taken_0x155468 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x15546Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155468u;
            // 0x15546c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155468) {
            ctx->pc = 0x155490u;
            goto label_155490;
        }
    }
    ctx->pc = 0x155470u;
    // 0x155470: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x155470u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x155474: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x155474u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155478: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x155478u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15547c: 0x91fc2  srl         $v1, $t1, 31
    ctx->pc = 0x15547cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x155480: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x155480u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x155484: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x155484u;
    {
        const bool branch_taken_0x155484 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155484u;
            // 0x155488: 0xad6300e8  sw          $v1, 0xE8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 232), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155484) {
            ctx->pc = 0x15549Cu;
            goto label_15549c;
        }
    }
    ctx->pc = 0x15548Cu;
    // 0x15548c: 0x0  nop
    ctx->pc = 0x15548cu;
    // NOP
label_155490:
    // 0x155490: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x155490u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x155494: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x155494u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155498: 0xad6200e8  sw          $v0, 0xE8($t3)
    ctx->pc = 0x155498u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 232), GPR_U32(ctx, 2));
label_15549c:
    // 0x15549c: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x15549cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1554a0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1554a0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1554a4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1554a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1554a8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1554a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1554ac: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1554acu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1554b0: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1554b0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1554b4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1554b4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1554b8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1554b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1554bc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1554bcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1554c0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1554c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1554c4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1554c4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1554c8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1554c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1554cc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1554ccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1554d0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1554D0u;
    {
        const bool branch_taken_0x1554d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1554D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1554D0u;
            // 0x1554d4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1554d0) {
            ctx->pc = 0x1554E4u;
            goto label_1554e4;
        }
    }
    ctx->pc = 0x1554D8u;
label_1554d8:
    // 0x1554d8: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x1554d8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1554dc: 0xad6200e8  sw          $v0, 0xE8($t3)
    ctx->pc = 0x1554dcu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 232), GPR_U32(ctx, 2));
    // 0x1554e0: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1554e0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_1554e4:
    // 0x1554e4: 0x2942001d  slti        $v0, $t2, 0x1D
    ctx->pc = 0x1554e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x1554e8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1554E8u;
    {
        const bool branch_taken_0x1554e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1554ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1554E8u;
            // 0x1554ec: 0x91742  srl         $v0, $t1, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1554e8) {
            ctx->pc = 0x155560u;
            goto label_155560;
        }
    }
    ctx->pc = 0x1554F0u;
    // 0x1554f0: 0x254affe3  addiu       $t2, $t2, -0x1D
    ctx->pc = 0x1554f0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967267));
    // 0x1554f4: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1554F4u;
    {
        const bool branch_taken_0x1554f4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1554F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1554F4u;
            // 0x1554f8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1554f4) {
            ctx->pc = 0x155518u;
            goto label_155518;
        }
    }
    ctx->pc = 0x1554FCu;
    // 0x1554fc: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x1554fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x155500: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x155500u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155504: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x155504u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x155508: 0x91f42  srl         $v1, $t1, 29
    ctx->pc = 0x155508u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
    // 0x15550c: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x15550cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x155510: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155510u;
    {
        const bool branch_taken_0x155510 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155510u;
            // 0x155514: 0xad6300ec  sw          $v1, 0xEC($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 236), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155510) {
            ctx->pc = 0x155524u;
            goto label_155524;
        }
    }
    ctx->pc = 0x155518u;
label_155518:
    // 0x155518: 0x91742  srl         $v0, $t1, 29
    ctx->pc = 0x155518u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
    // 0x15551c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x15551cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155520: 0xad6200ec  sw          $v0, 0xEC($t3)
    ctx->pc = 0x155520u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 236), GPR_U32(ctx, 2));
label_155524:
    // 0x155524: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x155524u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155528: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155528u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15552c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15552cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155530: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155530u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155534: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155534u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155538: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155538u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15553c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15553cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155540: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155540u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155544: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155544u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155548: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155548u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15554c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15554cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155550: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155550u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155554: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155554u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155558: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155558u;
    {
        const bool branch_taken_0x155558 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15555Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155558u;
            // 0x15555c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155558) {
            ctx->pc = 0x15556Cu;
            goto label_15556c;
        }
    }
    ctx->pc = 0x155560u;
label_155560:
    // 0x155560: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x155560u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x155564: 0xad6200ec  sw          $v0, 0xEC($t3)
    ctx->pc = 0x155564u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 236), GPR_U32(ctx, 2));
    // 0x155568: 0x254a0003  addiu       $t2, $t2, 0x3
    ctx->pc = 0x155568u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 3));
label_15556c:
    // 0x15556c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15556cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_155570:
    // 0x155570: 0x14c20047  bne         $a2, $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x155570u;
    {
        const bool branch_taken_0x155570 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x155574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155570u;
            // 0x155574: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155570) {
            ctx->pc = 0x155690u;
            goto label_155690;
        }
    }
    ctx->pc = 0x155578u;
    // 0x155578: 0x2942001f  slti        $v0, $t2, 0x1F
    ctx->pc = 0x155578u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x15557c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15557Cu;
    {
        const bool branch_taken_0x15557c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15557Cu;
            // 0x155580: 0x917c2  srl         $v0, $t1, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15557c) {
            ctx->pc = 0x1555F8u;
            goto label_1555f8;
        }
    }
    ctx->pc = 0x155584u;
    // 0x155584: 0x254affe1  addiu       $t2, $t2, -0x1F
    ctx->pc = 0x155584u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967265));
    // 0x155588: 0x11400009  beqz        $t2, . + 4 + (0x9 << 2)
    ctx->pc = 0x155588u;
    {
        const bool branch_taken_0x155588 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x15558Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155588u;
            // 0x15558c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155588) {
            ctx->pc = 0x1555B0u;
            goto label_1555b0;
        }
    }
    ctx->pc = 0x155590u;
    // 0x155590: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x155590u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x155594: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x155594u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155598: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x155598u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15559c: 0x91fc2  srl         $v1, $t1, 31
    ctx->pc = 0x15559cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x1555a0: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x1555a0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x1555a4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1555A4u;
    {
        const bool branch_taken_0x1555a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1555A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1555A4u;
            // 0x1555a8: 0xad6300f0  sw          $v1, 0xF0($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 240), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1555a4) {
            ctx->pc = 0x1555BCu;
            goto label_1555bc;
        }
    }
    ctx->pc = 0x1555ACu;
    // 0x1555ac: 0x0  nop
    ctx->pc = 0x1555acu;
    // NOP
label_1555b0:
    // 0x1555b0: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x1555b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x1555b4: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1555b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1555b8: 0xad6200f0  sw          $v0, 0xF0($t3)
    ctx->pc = 0x1555b8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 240), GPR_U32(ctx, 2));
label_1555bc:
    // 0x1555bc: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x1555bcu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1555c0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1555c0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1555c4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1555c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1555c8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1555c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1555cc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1555ccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1555d0: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1555d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1555d4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1555d4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1555d8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1555d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1555dc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1555dcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1555e0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1555e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1555e4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1555e4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1555e8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1555e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1555ec: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1555ecu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1555f0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1555F0u;
    {
        const bool branch_taken_0x1555f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1555F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1555F0u;
            // 0x1555f4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1555f0) {
            ctx->pc = 0x155604u;
            goto label_155604;
        }
    }
    ctx->pc = 0x1555F8u;
label_1555f8:
    // 0x1555f8: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x1555f8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1555fc: 0xad6200f0  sw          $v0, 0xF0($t3)
    ctx->pc = 0x1555fcu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 240), GPR_U32(ctx, 2));
    // 0x155600: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x155600u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_155604:
    // 0x155604: 0x2942001d  slti        $v0, $t2, 0x1D
    ctx->pc = 0x155604u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x155608: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x155608u;
    {
        const bool branch_taken_0x155608 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15560Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155608u;
            // 0x15560c: 0x91742  srl         $v0, $t1, 29 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155608) {
            ctx->pc = 0x155680u;
            goto label_155680;
        }
    }
    ctx->pc = 0x155610u;
    // 0x155610: 0x254affe3  addiu       $t2, $t2, -0x1D
    ctx->pc = 0x155610u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967267));
    // 0x155614: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x155614u;
    {
        const bool branch_taken_0x155614 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x155618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155614u;
            // 0x155618: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155614) {
            ctx->pc = 0x155638u;
            goto label_155638;
        }
    }
    ctx->pc = 0x15561Cu;
    // 0x15561c: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x15561cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x155620: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x155620u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155624: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x155624u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x155628: 0x91f42  srl         $v1, $t1, 29
    ctx->pc = 0x155628u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
    // 0x15562c: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x15562cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x155630: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155630u;
    {
        const bool branch_taken_0x155630 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155630u;
            // 0x155634: 0xad6300f4  sw          $v1, 0xF4($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 244), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155630) {
            ctx->pc = 0x155644u;
            goto label_155644;
        }
    }
    ctx->pc = 0x155638u;
label_155638:
    // 0x155638: 0x91742  srl         $v0, $t1, 29
    ctx->pc = 0x155638u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 29));
    // 0x15563c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x15563cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155640: 0xad6200f4  sw          $v0, 0xF4($t3)
    ctx->pc = 0x155640u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 244), GPR_U32(ctx, 2));
label_155644:
    // 0x155644: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x155644u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155648: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155648u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15564c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15564cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155650: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155650u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155654: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155654u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155658: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155658u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15565c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15565cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155660: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155660u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155664: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155664u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155668: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155668u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15566c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15566cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155670: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155670u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155674: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155674u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155678: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155678u;
    {
        const bool branch_taken_0x155678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15567Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155678u;
            // 0x15567c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155678) {
            ctx->pc = 0x15568Cu;
            goto label_15568c;
        }
    }
    ctx->pc = 0x155680u;
label_155680:
    // 0x155680: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x155680u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x155684: 0xad6200f4  sw          $v0, 0xF4($t3)
    ctx->pc = 0x155684u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 244), GPR_U32(ctx, 2));
    // 0x155688: 0x254a0003  addiu       $t2, $t2, 0x3
    ctx->pc = 0x155688u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 3));
label_15568c:
    // 0x15568c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x15568cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_155690:
    // 0x155690: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x155690u;
    {
        const bool branch_taken_0x155690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155690u;
            // 0x155694: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155690) {
            ctx->pc = 0x15571Cu;
            goto label_15571c;
        }
    }
    ctx->pc = 0x155698u;
label_155698:
    // 0x155698: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x155698u;
    {
        const bool branch_taken_0x155698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15569Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155698u;
            // 0x15569c: 0x91602  srl         $v0, $t1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155698) {
            ctx->pc = 0x155710u;
            goto label_155710;
        }
    }
    ctx->pc = 0x1556A0u;
    // 0x1556a0: 0x254affe8  addiu       $t2, $t2, -0x18
    ctx->pc = 0x1556a0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967272));
    // 0x1556a4: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1556A4u;
    {
        const bool branch_taken_0x1556a4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1556A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1556A4u;
            // 0x1556a8: 0xaa1023  subu        $v0, $a1, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1556a4) {
            ctx->pc = 0x1556C8u;
            goto label_1556c8;
        }
    }
    ctx->pc = 0x1556ACu;
    // 0x1556ac: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1556acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x1556b0: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x1556b0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x1556b4: 0x91e02  srl         $v1, $t1, 24
    ctx->pc = 0x1556b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 24));
    // 0x1556b8: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x1556b8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x1556bc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1556BCu;
    {
        const bool branch_taken_0x1556bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1556C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1556BCu;
            // 0x1556c0: 0xad6300fc  sw          $v1, 0xFC($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 252), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1556bc) {
            ctx->pc = 0x1556D4u;
            goto label_1556d4;
        }
    }
    ctx->pc = 0x1556C4u;
    // 0x1556c4: 0x0  nop
    ctx->pc = 0x1556c4u;
    // NOP
label_1556c8:
    // 0x1556c8: 0x91602  srl         $v0, $t1, 24
    ctx->pc = 0x1556c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 24));
    // 0x1556cc: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1556ccu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1556d0: 0xad6200fc  sw          $v0, 0xFC($t3)
    ctx->pc = 0x1556d0u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 252), GPR_U32(ctx, 2));
label_1556d4:
    // 0x1556d4: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x1556d4u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1556d8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1556d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1556dc: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1556dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1556e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1556e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1556e4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1556e4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1556e8: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1556e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1556ec: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1556ecu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1556f0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1556f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1556f4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1556f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1556f8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1556f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1556fc: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1556fcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155700: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155700u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155704: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x155704u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155708: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155708u;
    {
        const bool branch_taken_0x155708 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15570Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155708u;
            // 0x15570c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155708) {
            ctx->pc = 0x15571Cu;
            goto label_15571c;
        }
    }
    ctx->pc = 0x155710u;
label_155710:
    // 0x155710: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x155710u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x155714: 0xad6200fc  sw          $v0, 0xFC($t3)
    ctx->pc = 0x155714u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 252), GPR_U32(ctx, 2));
    // 0x155718: 0x254a0008  addiu       $t2, $t2, 0x8
    ctx->pc = 0x155718u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 8));
label_15571c:
    // 0x15571c: 0x2942001f  slti        $v0, $t2, 0x1F
    ctx->pc = 0x15571cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x155720: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x155720u;
    {
        const bool branch_taken_0x155720 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155720u;
            // 0x155724: 0x917c2  srl         $v0, $t1, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155720) {
            ctx->pc = 0x155798u;
            goto label_155798;
        }
    }
    ctx->pc = 0x155728u;
    // 0x155728: 0x254affe1  addiu       $t2, $t2, -0x1F
    ctx->pc = 0x155728u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967265));
    // 0x15572c: 0x11400008  beqz        $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x15572Cu;
    {
        const bool branch_taken_0x15572c = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x155730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15572Cu;
            // 0x155730: 0x8a1023  subu        $v0, $a0, $t2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15572c) {
            ctx->pc = 0x155750u;
            goto label_155750;
        }
    }
    ctx->pc = 0x155734u;
    // 0x155734: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x155734u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x155738: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x155738u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x15573c: 0x91fc2  srl         $v1, $t1, 31
    ctx->pc = 0x15573cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x155740: 0x1474804  sllv        $t1, $a3, $t2
    ctx->pc = 0x155740u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 10) & 0x1F));
    // 0x155744: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x155744u;
    {
        const bool branch_taken_0x155744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155744u;
            // 0x155748: 0xad6300f8  sw          $v1, 0xF8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 248), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155744) {
            ctx->pc = 0x15575Cu;
            goto label_15575c;
        }
    }
    ctx->pc = 0x15574Cu;
    // 0x15574c: 0x0  nop
    ctx->pc = 0x15574cu;
    // NOP
label_155750:
    // 0x155750: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x155750u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x155754: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x155754u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155758: 0xad6200f8  sw          $v0, 0xF8($t3)
    ctx->pc = 0x155758u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 248), GPR_U32(ctx, 2));
label_15575c:
    // 0x15575c: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x15575cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155760: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155760u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x155764: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155764u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155768: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155768u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15576c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15576cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155770: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x155770u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155774: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x155774u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x155778: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155778u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15577c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15577cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155780: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x155780u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x155784: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x155784u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x155788: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x155788u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15578c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15578cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x155790: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x155790u;
    {
        const bool branch_taken_0x155790 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155790u;
            // 0x155794: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155790) {
            ctx->pc = 0x1557A4u;
            goto label_1557a4;
        }
    }
    ctx->pc = 0x155798u;
label_155798:
    // 0x155798: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x155798u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x15579c: 0xad6200f8  sw          $v0, 0xF8($t3)
    ctx->pc = 0x15579cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 248), GPR_U32(ctx, 2));
    // 0x1557a0: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1557a0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_1557a4:
    // 0x1557a4: 0x8d6200f8  lw          $v0, 0xF8($t3)
    ctx->pc = 0x1557a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 248)));
    // 0x1557a8: 0x5440ffbb  bnel        $v0, $zero, . + 4 + (-0x45 << 2)
    ctx->pc = 0x1557A8u;
    {
        const bool branch_taken_0x1557a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1557a8) {
            ctx->pc = 0x1557ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1557A8u;
            // 0x1557ac: 0x29420018  slti        $v0, $t2, 0x18 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)24) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x155698u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155698;
        }
    }
    ctx->pc = 0x1557B0u;
    // 0x1557b0: 0x10c1823  subu        $v1, $t0, $t4
    ctx->pc = 0x1557b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0x1557b4: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1557b4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1557b8: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1557b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1557bc: 0xcb3021  addu        $a2, $a2, $t3
    ctx->pc = 0x1557bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    // 0x1557c0: 0x1431821  addu        $v1, $t2, $v1
    ctx->pc = 0x1557c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x1557c4: 0x24c604fc  addiu       $a2, $a2, 0x4FC
    ctx->pc = 0x1557c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1276));
    // 0x1557c8: 0x2462ffc7  addiu       $v0, $v1, -0x39
    ctx->pc = 0x1557c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967239));
    // 0x1557cc: 0x2463ffce  addiu       $v1, $v1, -0x32
    ctx->pc = 0x1557ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967246));
    // 0x1557d0: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1557d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1557d4: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x1557d4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1557d8: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x1557d8u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x1557dc: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1557dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1557e0: 0x24070010  addiu       $a3, $zero, 0x10
    ctx->pc = 0x1557e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1557e4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1557e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1557e8: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x1557e8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x1557ec: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1557ecu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1557f0: 0x1821021  addu        $v0, $t4, $v0
    ctx->pc = 0x1557f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 2)));
    // 0x1557f4: 0xad63032c  sw          $v1, 0x32C($t3)
    ctx->pc = 0x1557f4u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 812), GPR_U32(ctx, 3));
    // 0x1557f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1557F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1557FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1557F8u;
            // 0x1557fc: 0xad670328  sw          $a3, 0x328($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 808), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155268u: goto label_155268;
            case 0x155270u: goto label_155270;
            case 0x1552D8u: goto label_1552d8;
            case 0x1552E4u: goto label_1552e4;
            case 0x155320u: goto label_155320;
            case 0x155330u: goto label_155330;
            case 0x155368u: goto label_155368;
            case 0x155374u: goto label_155374;
            case 0x1553B0u: goto label_1553b0;
            case 0x1553BCu: goto label_1553bc;
            case 0x1553F0u: goto label_1553f0;
            case 0x1553FCu: goto label_1553fc;
            case 0x155438u: goto label_155438;
            case 0x155444u: goto label_155444;
            case 0x155490u: goto label_155490;
            case 0x15549Cu: goto label_15549c;
            case 0x1554D8u: goto label_1554d8;
            case 0x1554E4u: goto label_1554e4;
            case 0x155518u: goto label_155518;
            case 0x155524u: goto label_155524;
            case 0x155560u: goto label_155560;
            case 0x15556Cu: goto label_15556c;
            case 0x155570u: goto label_155570;
            case 0x1555B0u: goto label_1555b0;
            case 0x1555BCu: goto label_1555bc;
            case 0x1555F8u: goto label_1555f8;
            case 0x155604u: goto label_155604;
            case 0x155638u: goto label_155638;
            case 0x155644u: goto label_155644;
            case 0x155680u: goto label_155680;
            case 0x15568Cu: goto label_15568c;
            case 0x155690u: goto label_155690;
            case 0x155698u: goto label_155698;
            case 0x1556C8u: goto label_1556c8;
            case 0x1556D4u: goto label_1556d4;
            case 0x155710u: goto label_155710;
            case 0x15571Cu: goto label_15571c;
            case 0x155750u: goto label_155750;
            case 0x15575Cu: goto label_15575c;
            case 0x155798u: goto label_155798;
            case 0x1557A4u: goto label_1557a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
